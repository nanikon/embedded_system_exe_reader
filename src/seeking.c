//
// Created by natan on 05.03.2022.
//

#include "seeking.h"

bool seek_to_pe_header(FILE* in, struct IMAGE_DOS_HEADER* header) {
    return fseek(in, header->e_lfanew, SEEK_SET) == 0;
}

bool seek_to_section_table(FILE* in, struct IMAGE_DOS_HEADER* dos_header, struct IMAGE_NT_HEADER* header) {
    return fseek(in, dos_header->e_lfanew + header->FileHeader.SizeOfOptionalHeader + sizeof(struct IMAGE_FILE_HEADER) + sizeof (DWORD), SEEK_SET) == 0;
}