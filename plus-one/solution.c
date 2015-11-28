/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i, point, *new_array = NULL;
    for (i = digitsSize - 1, point = 1; i >= 0; --i) {
        if (digits[i] + point >= 10) {
            digits[i] = digits[i] + point - 10;
            point = 1;
        } else {
            digits[i] = digits[i] + point;
            point = 0;
        }
    }
    if (point) {
        *returnSize = digitsSize + 1;
        new_array = malloc(*returnSize * sizeof(*new_array));
        new_array[0] = 1;
        for (i = 1; i < *returnSize; ++i)
            new_array[i] = digits[i - 1];
        return new_array;
    } else {
        *returnSize = digitsSize;        
        return digits;
    }
}
