int climbStairs(int n) {
    int i, *sequence;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    sequence = malloc(n * sizeof(*sequence));
    sequence[0] = 1;
    sequence[1] = 2;
    for (i = 2; i < n; ++i)
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    return sequence[i - 1];
}
