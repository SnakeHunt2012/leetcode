#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int i = 0, offset = 0;
    while (i + offset < numsSize)
	if (nums[i + offset]) {
	    nums[i] = nums[i + offset];
	    ++i;
	}
	else
	    ++offset;
    while (i < numsSize)
	nums[i++] = 0;
}
