/*
Check if any two intervals overlap.

1. Sort the intervals according to start time and traverse.

2. if (interval[i-1].end >= interval[i].start)
	return true;





Another method

Create array of size (max number)
For any interval {i,j}, increment arr[i]++ and arr[j+1]--
Computer prefix sum from i to j

For first time prefix sum will look like
0 0 0 0 0 0 0 0 ...... 0 1 1 1 1 1 1 1 ...... 0 0 0 0 0 0

While calculating prefix sums, if we get any value in prefix array as 2, then return true

*/