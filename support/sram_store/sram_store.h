#ifndef SRAM_STORE_H
#define SRAM_STORE_H

#include <stdbool.h>
#include <stdint.h>

#include "file_io.h"

void sram_store_reset();
void sram_store_before_mount(uint8_t slot);
bool sram_store_mount_virtual(uint8_t slot, const char *save_path, int pre_size, fileTYPE *img);
void sram_store_after_write(uint8_t slot);
void sram_store_poll();

#endif
