#ifndef SQLITE_SRAM_H
#define SQLITE_SRAM_H

#include <stdbool.h>
#include <stdint.h>

#include "file_io.h"

struct sram_store_tagged_snapshot_t;

void sqlite_sram_reset();
bool sqlite_sram_mount_virtual(uint8_t slot, const char *save_path, int pre_size, fileTYPE *img);
void sqlite_sram_unmount_slot(uint8_t slot);
void sqlite_sram_mark_save_dirty(uint8_t slot);
void sqlite_sram_flush_slot(uint8_t slot);
void sqlite_sram_poll();
bool sqlite_sram_ui_available();
bool sqlite_sram_tag_latest(const char *tag);
int sqlite_sram_list_tagged(sram_store_tagged_snapshot_t *out, int max_items);
bool sqlite_sram_restore_tagged(int64_t snapshot_id);
bool sqlite_sram_delete_tagged(int64_t snapshot_id);

#endif
