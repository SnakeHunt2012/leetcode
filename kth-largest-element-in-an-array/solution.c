#define exch(A, B) { int t = A; A = B; B = t; }

int partition(int data[], int left, int right)
{
    int i = left - 1, j = right;
    for (;;) {
        while (data[++i] < data[right]) ;
        while (data[--j] > data[right]) if (j <= left) break;
        if (i >= j) break;
        exch(data[i], data[j]);
    }
    exch(data[i], data[right]);
    return i;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int i, left = 0, right = numsSize - 1;
    for (;;) {
        printf("left = %d, right = %d, ", left, right);
        i = partition(nums, left, right);
        printf("i = %d, numsSize - k = %d\n", i, numsSize - k);
        if (i == numsSize - k) break;
        if (i < numsSize - k) left = i + 1;
        if (i > numsSize - k) right = i - 1;
    }
    return nums[numsSize - k];
}
