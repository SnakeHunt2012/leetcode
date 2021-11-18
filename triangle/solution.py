class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        triangle_dp_last = [0] * len(triangle)
        triangle_dp_next = [0] * len(triangle)
        for i in range(len(triangle)):
            if i <= 0:
                triangle_dp_next[0] = triangle[0][0]
            else:
                for j in range(i + 1):
                    if j == 0:
                        triangle_dp_next[j] = triangle[i][j] + triangle_dp_last[j]
                    elif j == i:
                        triangle_dp_next[j] = triangle[i][j] + triangle_dp_last[j - 1]
                    else:
                        triangle_dp_next[j] = triangle[i][j] + min(triangle_dp_last[j], triangle_dp_last[j - 1])
            triangle_dp_last, triangle_dp_next = triangle_dp_next, triangle_dp_last
        return min(triangle_dp_last)
