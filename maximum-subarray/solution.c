int maxSubArray(int* nums, int numsSize) {
    int i, count, max_value, max_count;

    if (numsSize == 1)
        return nums[0];

    for (i = 1, max_value = nums[0]; i < numsSize; ++i)
        max_value = (nums[i] > max_value) ? nums[i] : max_value;
        
    for (i = count = max_count = 0; i < numsSize; ++i) {
        if (count + nums[i] < 0)
            count = 0;
        else
            count += nums[i];
        max_count = count > max_count ? count : max_count;
    }

    return (max_value > 0) ? max_count : max_value;
}
