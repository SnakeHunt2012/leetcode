int maxArea(int* height, int heightSize) {
    int i = 0, j = heightSize - 1, maxArea = 0;
    while (i <= j) {
        int area = (j - i) * ((height[i] > height[j]) ? height[j] : height[i]);
        if (area > maxArea) maxArea = area;
        (height[i] < height[j]) ? ++i : --j;
    }
    return maxArea;
}
