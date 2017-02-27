int reverse(int x) {
    int sign, tail;
    unsigned long res;

    sign = (x < 0) ? -1 : 1;
    x = (x < 0) ? -x : x;
    
    for (res = tail = 0; x != 0; x /= 10)
        res = res * 10 + x % 10;
    if ((sign == -1 && res > 2147483648) || (sign == 1 && res > 2147483647))
        return 0;
    return sign * res;
}
