//
// Created by natan on 05.03.2022.
//

#ifndef FIRST_SECTION_H
#define FIRST_SECTION_H

#include "size.h"
#include "stdbool.h"

#include <stdio.h>

#define IMAGE_SIZEOF_SHORT_NAME 8
#define CODE_FLAG 0x00000020

struct IMAGE_SECTION_HEADER {
    BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
    union {
        DWORD PhysicalAddress;
        DWORD VirtualSize;
    } Misc;
    DWORD VirtualAddress;
    DWORD SizeOfRawData;
    DWORD PointerToRawData;
    DWORD PointerToRelocations;
    DWORD PointerToLinenumbers;
    WORD  NumberOfRelocations;
    WORD  NumberOfLinenumbers;
    DWORD Characteristics;
};

bool read_section(FILE* in, struct IMAGE_SECTION_HEADER* section);
void print_info(FILE* out, struct IMAGE_SECTION_HEADER* section);

#endif //FIRST_SECTION_H
