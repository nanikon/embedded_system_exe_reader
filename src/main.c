#include <stdio.h>
#include <inttypes.h>
#include <errno.h>

#include "file_manager.h"
#include "section.h"
#include "headers.h"
#include "seeking.h"

// первый аргумент - исходный файл
// второй аргумент - файл, куда сохраняется информация о секциях и точке входа (текстовый вид)
int main( int argc, char** argv ) {
    if (argc != 3) {
        fprintf(stderr, "Expect 2 arguments: 1 - name of input program, 2 - name of file to write meta info\n");
        return -1;
    }
    char* source_filename = argv[1];
    char* info_target_filename = argv[2];

    FILE* source = NULL;
    FILE* info_target = NULL;

    if (!file_open_to_read(&source, source_filename)) {
        fprintf(stderr, "Can't open first file\n");
        return -1;
    }
    fprintf(stderr, "Open file %s to read\n", source_filename);
    if (!file_open_to_write_text(&info_target, info_target_filename)) {
        fprintf(stderr, "Can't open second file\n");
        return -1;
    }

    struct IMAGE_DOS_HEADER dos_header = {0};
    if (!read_dos_header(source, &dos_header)) {
        perror("Invalid DOS header\n");
        fprintf(stderr, "Invalid DOS header\n");
        return -1;
    }
    if (!seek_to_pe_header(source, &dos_header)) {
        fprintf(stderr, "Can't seek to start pe header\n");
        return -1;
    }

    struct IMAGE_NT_HEADER pe_header = {0};
    if (!read_pe_header(source, &pe_header)) {
        fprintf(stderr, "Invalid PE header\n");
        return -1;
    }
    print_entry_point(info_target, &pe_header);

    if (!seek_to_section_table(source, &dos_header, &pe_header)) {
        fprintf(stderr, "Can't seek to section table\n");
        return -1;
    }


    for (uint16_t i = 0; i < pe_header.FileHeader.NumberOfSections; i++) {
        struct IMAGE_SECTION_HEADER section = {0};
        if (!read_section(source, &section)) {
            fprintf(stderr, "Can't read section number %" PRIu16, i + 1);
            return -1;
        }
        print_info(info_target, &section);
    }

    return 0;
}
