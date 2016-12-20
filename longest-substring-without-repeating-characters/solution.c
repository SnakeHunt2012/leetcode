int lengthOfLongestSubstring(char* s) {
    int head, tail, length, record[128];
    for (head = 0; head < 128; record[head++] = -1) ;
    for (head = tail = length = 0; s[tail] != '\0'; ++tail) {
        if (record[s[tail]] >= head)
            head = record[s[tail]] + 1;
        if (tail - head + 1 > length)
            length = tail - head + 1;
        record[s[tail]] = tail;
    }
    return length;
}
