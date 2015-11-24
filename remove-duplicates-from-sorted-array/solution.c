int removeDuplicates(int* nums, int numsSize) {
    int i, j;
    if (numsSize < 2)
        return numsSize;
    for (i = 0, j = 1; j < numsSize; ++j)
        if (nums[i] != nums[j])
            nums[++i] = nums[j];
    return i + 1;
}
