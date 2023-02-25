//
// Created by natan on 05.03.2022.
//

#ifndef FIRST_SEEKING_H
#define FIRST_SEEKING_H

#include "headers.h"
#include <stdio.h>

bool seek_to_pe_header(FILE* in, struct IMAGE_DOS_HEADER* header);

bool seek_to_section_table(FILE* in, struct IMAGE_DOS_HEADER* dos_header, struct IMAGE_NT_HEADER* header);

#endif //FIRST_SEEKING_H
