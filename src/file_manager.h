//
// Created by natan on 05.03.2022.
//

#ifndef FIRST_FILE_MANAGER_H
#define FIRST_FILE_MANAGER_H

#include <stdio.h>
#include <stdbool.h>

bool file_open_to_read(FILE** file, const char* file_name);

bool file_open_to_write_text(FILE** file, const char* file_name);

bool file_open_to_write_bin(FILE** file, const char* file_name);

bool file_close(FILE* file);

#endif //FIRST_FILE_MANAGER_H
