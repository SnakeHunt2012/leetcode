double myPow(double x, int n) {
    bool negative = n < 0;
    double base, power;
    if (negative) {
        n *= -1;
    }
    if (x == 0)
        return n ? 0 : 1;
    if (x == 1)
        return 1;
    if (x == -1)
        return n & 0x00000001 ? -1 : 1;
    for (base = x, power = 1.0; n; n >>= 1, base *= base)
        if (n & 0x00000001)
            power *= base;
    return negative ? 1 / power : power;
}
