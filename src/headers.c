//
// Created by natan on 05.03.2022.
//

#include "headers.h"

bool read_dos_header(FILE* in, struct IMAGE_DOS_HEADER* header) {
    size_t result = fread(header, sizeof(struct IMAGE_DOS_HEADER), 1, in);
    return result == 1 && header->e_magic == ZM;
}

bool read_pe_header(FILE* in, struct IMAGE_NT_HEADER* header) {
    size_t result = fread(header, sizeof(struct IMAGE_NT_HEADER), 1, in);
    return result == 1 && header->Signature == SIGNATURE;
}

void print_entry_point(FILE* out, struct IMAGE_NT_HEADER* header) {
    fprintf(out, "Entry point:\t%X\n\n", header->OptionalHeader.AddressOfEntryPoint);
}
