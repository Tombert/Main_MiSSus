#include "support/sram_store/sram_store.h"

#include "support/sqlite_sram/sqlite_sram.h"

void sram_store_reset()
{
	sqlite_sram_reset();
}

void sram_store_before_mount(uint8_t slot)
{
	sqlite_sram_flush_slot(slot);
	sqlite_sram_unmount_slot(slot);
}

bool sram_store_mount_virtual(uint8_t slot, const char *save_path, int pre_size, fileTYPE *img)
{
	return sqlite_sram_mount_virtual(slot, save_path, pre_size, img);
}

void sram_store_after_write(uint8_t slot)
{
	sqlite_sram_mark_save_dirty(slot);
	sqlite_sram_flush_slot(slot);
}

void sram_store_poll()
{
	sqlite_sram_poll();
}

bool sram_store_ui_available()
{
	return sqlite_sram_ui_available();
}

bool sram_store_tag_latest(const char *tag)
{
	return sqlite_sram_tag_latest(tag);
}

int sram_store_list_tagged(sram_store_tagged_snapshot_t *out, int max_items)
{
	return sqlite_sram_list_tagged(out, max_items);
}

bool sram_store_restore_tagged(int64_t snapshot_id)
{
	return sqlite_sram_restore_tagged(snapshot_id);
}

bool sram_store_delete_tagged(int64_t snapshot_id)
{
	return sqlite_sram_delete_tagged(snapshot_id);
}
