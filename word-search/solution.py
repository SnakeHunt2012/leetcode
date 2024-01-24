class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])

        def search(i, j, word):
            if len(word) == 0:
                return True

            if i < 0 or j < 0 or i >= m or j >= n:
                return False
            
            if board[i][j] != word[0]:
                return False

            value = board[i][j]
            board[i][j] = ""
            if search(i - 1, j, word[1:]) or search(i + 1, j, word[1:]) or search(i, j - 1, word[1:]) or search(i, j + 1, word[1:]):
                return True
            board[i][j] = value
            
            return False

        for i in range(0, m):
            for j in range(0, n):
                if search(i, j, word):
                    return True
        return False
