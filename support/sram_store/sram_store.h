#ifndef SRAM_STORE_H
#define SRAM_STORE_H

#include <stdbool.h>
#include <stdint.h>

#include "file_io.h"

#define SRAM_STORE_TAG_MAX_LEN 64

struct sram_store_tagged_snapshot_t
{
	int64_t id;
	int64_t ts_ms;
	char tag[SRAM_STORE_TAG_MAX_LEN];
};

void sram_store_reset();
void sram_store_before_mount(uint8_t slot);
bool sram_store_mount_virtual(uint8_t slot, const char *save_path, int pre_size, fileTYPE *img);
void sram_store_after_write(uint8_t slot);
void sram_store_poll();
bool sram_store_ui_available();
bool sram_store_tag_latest(const char *tag);
int sram_store_list_tagged(sram_store_tagged_snapshot_t *out, int max_items);
bool sram_store_restore_tagged(int64_t snapshot_id);
bool sram_store_delete_tagged(int64_t snapshot_id);

#endif
