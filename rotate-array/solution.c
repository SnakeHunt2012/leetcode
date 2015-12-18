#define exch(A, B) { int temp = A; A = B; B = temp; }

void rotate(int* nums, int numsSize, int k) {
    int head, tail;
    
    k %= numsSize;
    if (!k)
        return;
    
    for (head = 0, tail = numsSize - 1; head < tail; ++head, --tail)
        exch(nums[head], nums[tail]);
    for (head = 0, tail = k - 1; head < tail; ++head, --tail)
        exch(nums[head], nums[tail]);
    for (head = k, tail = numsSize - 1; head < tail; ++head, --tail)
        exch(nums[head], nums[tail]);
}
