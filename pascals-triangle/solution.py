class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows <= 0:
            return []
        elif numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1], [1, 1]]
        else:
            pascal_triangle = self.generate(numRows - 1)
            last_row = pascal_triangle[-1]
            next_row = [1] + [last_row[index] + last_row[index + 1] for index in range(len(last_row) - 1)] + [1]
            pascal_triangle.append(next_row)
            return pascal_triangle
