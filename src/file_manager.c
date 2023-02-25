//
// Created by natan on 05.03.2022.
//

#include "file_manager.h"

bool file_open_to_read(FILE** file, const char* file_name) {
    *file = fopen(file_name, "rb");
    if (*file) { return true; }
    else { return false; }
}

bool file_open_to_write_text(FILE** file, const char* file_name) {
    *file = fopen(file_name, "wt");
    if (*file) { return true; }
    else { return false; }
}

bool file_open_to_write_bin(FILE** file, const char* file_name) {
    *file = fopen(file_name, "wb");
    if (*file) { return true; }
    else { return false; }
}

bool file_close(FILE* file) {
    int result = fclose(file);
    return result == 0;
}