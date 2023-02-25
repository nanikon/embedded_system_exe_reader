//
// Created by natan on 05.03.2022.
//

#include "section.h"

bool read_section(FILE* in, struct IMAGE_SECTION_HEADER* section) {
    const size_t result = fread(section, sizeof(struct IMAGE_SECTION_HEADER), 1, in);
    return result == 1;
}

DWORD get_start_section(struct IMAGE_SECTION_HEADER* section) { return section->PointerToRawData; }

bool is_code(struct IMAGE_SECTION_HEADER* section) {
    return section->Characteristics && CODE_FLAG;
}

void print_info(FILE* out, struct IMAGE_SECTION_HEADER* section) {
    fprintf(out, "Name:\t%.8s\n", section->Name);
    fprintf(out, "Virtual size:\t%X\n", section->Misc.VirtualSize);
    fprintf(out, "Size of raw data:\t%X\n", section->SizeOfRawData);
    fprintf(out, "Virtual address:\t%X\n", section->VirtualAddress);
    fprintf(out, "Pointer to raw data:\t%X\n\n", section->PointerToRawData);
}
