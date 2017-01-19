int find_kth_element(int *left_array, int left_length, int *right_array, int right_length, int k) {
    int decay = k / 2;
    if (left_length == 0) {
        printf("right_array[%d - 1]: %d\n", k, right_array[k - 1]);
        return right_array[k - 1];
    }
    if (right_length == 0) {
        printf("left_array[%d - 1]: %d\n", k, left_array[k - 1]);
        return left_array[k - 1];
    }
    if (decay == 0) {
        printf("(%d < %d) ? %d : %d: %d\n", *left_array, *right_array, *left_array, *right_array, (*left_array < *right_array) ? *left_array : *right_array);
        return (*left_array < *right_array) ? *left_array : *right_array;
    }
    
    decay = (decay > left_length) ? left_length : decay;
    decay = (decay > right_length) ? right_length : decay;
    if (left_array[decay - 1] < right_array[decay - 1])
        return find_kth_element(left_array + decay, left_length - decay, right_array, right_length, k - decay);
    else
        return find_kth_element(left_array, left_length, right_array + decay, right_length - decay, k - decay);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if ((nums1Size + nums2Size) % 2)
        return (double) find_kth_element(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2 + 1);
    else
        return ((double) find_kth_element(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2) +
                (double) find_kth_element(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2 + 1)) / 2;
}
