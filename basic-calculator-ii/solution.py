import re
import operator

class Solution:
    # @param {string} s
    # @return {integer}
    def calculate(self, s):

        op_dict = {
            '+': operator.add,
            '-': operator.sub,
            '*': operator.mul,
            '/': operator.floordiv
        }
        
        token_list = re.sub("\d+", " \g<0> ", s).split()

        final_result = 0
        temporary_result = 0
        last_op = '+'

        index = 0
        while index < len(token_list):
            token = token_list[index]
            if token in "+-":
                final_result = op_dict[last_op](final_result, temporary_result)
                last_op = token
                temporary_result = 0
            elif token in "*/":
                index = index + 1
                temporary_result = op_dict[token](temporary_result, int(token_list[index]))
            else: # token is number
                temporary_result = int(token)
            index += 1

        final_result = op_dict[last_op](final_result, temporary_result)
        
        return final_result
    
def main():

    input = "33+0*22"
    print Solution().calculate(input)

    input = " 0/22 "
    print Solution().calculate(input)
    
    input = " 33+55 / 22 "
    print Solution().calculate(input)

    input = ""

    Solution().calculate(input)
    

if __name__ == "__main__":

    main()
                    
