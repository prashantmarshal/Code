1. Take an auxiliary array of type
struct {
	element,
	old_index
}

2. sort the array
3. now we have old_index and new_index for element.
4. create graph where edges start from old old_index to new_index.

5. we will have many cycles corresponding to shiftings.
6. swaps = cycle_size - 1 	...  for all cycles.

https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
