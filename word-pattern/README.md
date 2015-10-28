Word Pattern
============

Given a pattern and a string str, find if str follows the same pattern.

Examples:

    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.

Notes:

    patterncontains only lowercase alphabetical letters, and str contains words separated by a single space. Each word in str contains only lowercase alphabetical letters.
    Both pattern and str do not have leading or trailing spaces.
    Each letter in pattern must map to a word with length that is at least 1.
    