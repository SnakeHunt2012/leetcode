class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        length = len(s)
        dp = [False] * (length + 1)
        dp[0] = True

        word_set = set(wordDict)

        for length_i in range(length + 1):
            for length_j in range(length_i):
                if dp[length_j] and s[length_j:length_i] in word_set:
                    dp[length_i] = True
                    continue

        return dp[-1]
