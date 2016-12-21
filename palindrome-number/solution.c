bool isPalindrome(int x) {
    int y, z = 0;
    for (y = x; y != 0; y /= 10)
        z = z * 10 + y % 10;
    return (x >= 0 && z == x);
}
