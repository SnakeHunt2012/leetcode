#define red_color 0
#define white_color 1
#define blue_color 2

void sortColors(int* nums, int numsSize) {
    int i, red_count = 0, white_count = 0, blue_count = 0;
    for (i = 0 ; i < numsSize; ++i)
        switch (nums[i]) {
        case red_color:
            ++red_count;
            break;
        case white_color:
            ++white_count;
            break;
        case blue_color:
            ++blue_count;
            break;
        }
    for (i = 0; i < red_count; ++i)
        nums[i] = red_color;
    for (; i < red_count + white_count; ++i)
        nums[i] = white_color;
    for (; i < red_count + white_count + blue_count; ++i)
        nums[i] = blue_color;
}
