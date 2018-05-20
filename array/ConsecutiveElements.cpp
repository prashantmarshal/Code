1. check array size == max - min + 1.
2. check if all elements are distinct. this needs to be done via map checking if an array is repeated.

if both above conditions are true, return true;

https://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/


• the 2nd step can be avoided from taking extra space by setting arr[arr[i] - min] negative.
