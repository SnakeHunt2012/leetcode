/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * 2), left, right, middle;

    res[0] = res[1] = -1;
    *returnSize = 2;

    if (!numsSize || nums[0] > target || nums[numsSize - 1] < target) {
        return res;
    }

    // find the begin index of target
    // maintain: nums[left] < target && nums[right] >= target
    if (nums[0] == target) {
        res[0] = 0;
    } else {
        // maintain: nums[left] < target && nums[right] >= target
        for (left = 0, right = numsSize - 1, middle = (left + right) / 2; middle > left; middle = (left + right) / 2) {
            if (nums[middle] >= target) {
                right = middle;
            } else {
                left = middle;
            }
        }
        if (nums[right] == target) {
            res[0] = right;
        } else {
            return res;
        }
    }

    // find the end index of target
    // maintain: nums[left] <= target && nums[right] > target
    if (nums[numsSize - 1] == target) {
        res[1] = numsSize - 1;
    } else {
        // maintain: nums[left] <= target && nums[right] > target
        for (left = 0, right = numsSize - 1, middle = (left + right) / 2; middle > left; middle = (left + right) / 2) {
            if (nums[middle] > target) {
                right = middle;
            } else {
                left = middle;
            }
        }
        if (nums[left] == target) {
            res[1] = left;
        } else {
            return res;
        }
    }
    return res;
}
