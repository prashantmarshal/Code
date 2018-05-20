Check if any two intervals overlap.

1. Sort the intervals according to start time and traverse.

2. if (interval[i-1].end >= interval[i].start)
	return true;