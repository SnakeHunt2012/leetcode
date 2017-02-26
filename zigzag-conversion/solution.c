char* convert(char* s, int numRows) {
    int i, j, k, length = strlen(s);
    char *res;
    if (numRows == 1)
        return s;
    
    res = (char *) malloc(sizeof(char) * (length + 1));
    
    if (numRows == 2) {
        k = 0;
        for (i = 0; i < length; i += 2)
            res[k++] = s[i];
        for (i = 1; i < length; i += 2)
            res[k++] = s[i];
        res[k] = '\0';
        return res;
    }

    k = 0;
    for (j = 0; (2 * numRows - 2) * j < length; ++j)
        res[k++] = s[(2 * numRows - 2) * j];
    for (i = 1; i < numRows - 1; ++i)
        for (j = 0; (2 * numRows - 2) * j - i < length; ++j) {
            if ((2 * numRows - 2) * j - i >= 0 && (2 * numRows - 2) * j - i < length)
                res[k++] = s[(2 * numRows - 2) * j - i];
            if ((2 * numRows - 2) * j + i >= 0 && (2 * numRows - 2) * j + i < length)
                res[k++] = s[(2 * numRows - 2) * j + i];
        }
    for (j = 0; (2 * numRows - 2) * j + numRows - 1 < length; ++j)
        res[k++] = s[(2 * numRows - 2) * j + numRows - 1];
    res[k] = '\0';
    return res;
}
