double myPow(double x, int n) {
    bool negative = false;
    double base;
    
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    
    if (n & 0x80000000) {
        n *= -1;
        negative = true;
    }
    
    if (n & 0x00000001) {
        base = myPow(x, (n - 1) / 2);
        if (negative)
            return 1 / (base * base * x);
        else
            return base * base * x;
    } else {
        base = myPow(x, n / 2);
        if (negative)
            return 1 / (base * base);
        else
            return base * base;
    }
}
