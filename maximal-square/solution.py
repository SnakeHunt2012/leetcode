class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        m, n = len(matrix), len(matrix[0])
        dp = [[0] * n for i in range(m)]

        for i in range(m):
            if matrix[i][0] == '1':
                dp[i][0] = 1

        for i in range(n):
            if matrix[0][i] == '1':
                dp[0][i] = 1

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == '1':
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1

        length = max(max(line) for line in dp)
        return length * length
