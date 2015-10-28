class Solution:
    # @param {integer} n
    # @return {boolean}
    def isPowerOfTwo(self, n):

        if n <= 0:
            return False

        if n == 1:
            return True
        
        if n % 2 != 0:
            return False

        return self.isPowerOfTwo(n / 2)




        
