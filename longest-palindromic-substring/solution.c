#define MAX 1000

void copy(const char *src, char *des, const int left, const int right)
{
    int i;
    for (i = 0; i <= right - left; ++i)
        des[i] = src[left + i];
}

int odd_longest_length(const char *src, const int length, const int position)
{
    int i;
    for (i = 1; position + i < length && position - i >= 0 && src[position + i] == src[position - i]; ++i)
        ;
    return 2 * (i - 1) + 1;
}

int even_longest_length(const char *src, const int length, const int position)
{
    int i;
    for (i = 1; position + i - 1 < length && position - i >= 0 && src[position + i - 1] == src[position - i]; ++i)
        ;
    return 2 * (i - 1);
}

char* longestPalindrome(char* s) {
    int i, odd_longest[MAX], even_longest[MAX], length = strlen(s), max = 0, odd_flag = 0, center;
    char *target;
    for (i = 0; i < length; ++i)
        odd_longest[i] = odd_longest_length(s, length, i);
    for (i = 0; i < length; ++i)
        even_longest[i] = even_longest_length(s, length, i);

    // search odd_longest_length
    for (i = 0; i < length; ++i)
        if (odd_longest[i] > max) {
            max = odd_longest[i];
            center = i;
            odd_flag = 1;
        }

    // search even_longest_length
    for (i = 0; i < length; ++i)
        if (even_longest[i] > max) {
            max = even_longest[i];
            center = i;
            odd_flag = 0;
        }

    printf("max: %d\n", max);
    target = (char *) malloc(sizeof(char) * max + 1);
    if (odd_flag)
        copy(s, target, center - (max / 2), center + (max / 2));
    else
        copy(s, target, center - (max / 2), center + (max / 2) - 1);
    target[max] = '\0';
    return target;
}
