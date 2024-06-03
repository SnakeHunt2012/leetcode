class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        max_perfect_num = int(math.sqrt(n))
        dp = [1]

        for number in range(2, n + 1):
            min_num = number
            for i in range(1, max_perfect_num + 1):
                if number - i ** 2 > 0:
                    if dp[number - i ** 2 - 1] + 1 < min_num:
                        min_num = dp[number - i ** 2 - 1] + 1
                elif number - i ** 2 == 0:
                    min_num = 1
                else:
                    break
            dp.append(min_num)

        return dp[n - 1]
