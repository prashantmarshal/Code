struct semaphore {
	raw_spinlock_t          lock;
	unsigned int            count;
	struct list_head        wait_list;
};
