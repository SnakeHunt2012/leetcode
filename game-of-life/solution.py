from copy import deepcopy

class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        buffer = deepcopy(board)
        for i in range(0, len(board)):
            for j in range(0, len(board[i])):
                buffer[i][j] = self.compute(board, i, j)
                print "buffer[%r][%r]: %r" % (i, j, buffer[i][j])

        for i in range(0, len(board)):
            for j in range(0, len(board[i])):
                board[i][j] = buffer[i][j]

    def compute(self, board, i, j):

        board_height = len(board)
        board_width = len(board[0])

        counter = 0
        for row_index in range(i - 1, i + 2):
            for column_index in range(j - 1, j + 2):
                if row_index == i and column_index == j:
                    continue
                if row_index < 0 or row_index >= board_height:
                    continue
                if column_index < 0 or column_index >= board_width:
                    continue
                counter += board[row_index][column_index]

        if board[i][j] == 1: # live
            if counter < 2:
                return 0
            elif counter < 4:
                return 1
            else:
                return 0
        else:                # dead
            if counter == 3:
                return 1
            else:
                return 0
