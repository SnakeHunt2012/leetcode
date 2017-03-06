int trap(int* height, int heightSize) {
    int i, j, mark, area = 0;
    for (mark = i = 0; i < heightSize; ++i)
        if (height[i] > height[mark]) {
            area += (i - mark) * height[mark];
            mark = i;
        }

    i = mark;
    
    for (mark = j = heightSize - 1; j >= i; --j)
        if (height[j] > height[mark]) {
            area += (mark - j) * height[mark];
            mark = j;
        }

    area += (mark - i + 1) * height[mark];

    for (i = 0; i < heightSize; ++i)
        area -= height[i];
    return area;
}
