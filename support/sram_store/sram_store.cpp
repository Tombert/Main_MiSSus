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
