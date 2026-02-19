CREATE TABLE IF NOT EXISTS snapshot_tombstones (
	snapshot_id INTEGER PRIMARY KEY,
	ts_ms INTEGER NOT NULL
);
