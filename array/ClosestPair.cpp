Consider the following two arrays:
A: {1, 2, 11, 15}
B: {4, 12, 19, 23, 127, 235}

1. Suppose a pointer a points to the beginning of A and a pointer b points to the beginning of B.
The current difference between a and b is 3. Store this as the min.

2. How can we (potentially) make this difference smaller? Well, the value at b is bigger than the value at a,
so moving b will only make the difference larger. Therefore, we want to move a.

3. Now a points to 2 and b (still) points to 4. This difference is 2, so we should update min. Move a, since it is smaller.

4. Now a points to 11 and b points to 4. Move b.

5. Now a points to 11 and b points to 12. Update min to 1. Move b. And so on.