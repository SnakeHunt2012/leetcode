int trap(int* height, int heightSize) {
    int i, j, mark, area = 0, *scale = (int *) malloc((heightSize + 1) * sizeof(int));
    for (i = scale[0] = 0; i < heightSize; ++i) {
        scale[i] = (scale[i] < height[i]) ? height[i] : scale[i];
        scale[i + 1] = height[i];
    }

    for (mark = i = 0; i < heightSize; ++i)
        if (scale[i] >= scale[mark]) {
            area += (i - mark) * scale[mark];
            mark = i;
        }

    i = mark;
    
    for (mark = j = heightSize; j >= i; --j)
        if (scale[j] >= scale[mark]) {
            area += (mark - j) * scale[mark];
            mark = j;
        }

    for (i = 0; i < heightSize; ++i)
        area -= height[i];
    return area;
}
