#ifndef SQLITE_SRAM_H
#define SQLITE_SRAM_H

#include <stdbool.h>
#include <stdint.h>

#include "file_io.h"

void sqlite_sram_reset();
int sqlite_sram_runtime_enabled();
bool sqlite_sram_mount_virtual(uint8_t slot, const char *save_path, int pre_size, fileTYPE *img);
void sqlite_sram_unmount_slot(uint8_t slot);
bool sqlite_sram_slot_enabled(uint8_t slot);
void sqlite_sram_mark_save_dirty(uint8_t slot);
void sqlite_sram_flush_slot(uint8_t slot);
void sqlite_sram_poll();

#endif
