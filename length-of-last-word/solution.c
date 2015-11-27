int lengthOfLastWord(char* s) {
    int i, current_count, last_count;
    for (i = current_count = last_count = 0; s[i] != '\0'; ++i)
        if (isalpha(s[i]))
            current_count++;
        else {
            last_count = current_count ? current_count : last_count;
            current_count = 0;
        }
    return current_count ? current_count : last_count;
}
