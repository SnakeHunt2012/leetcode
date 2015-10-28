class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def majorityElement(self, nums):

        majority = None
        counter = 0

        for number in nums:
            if counter == 0 or majority is None:
                majority = number
                counter = 1
                continue

            if majority == number:
                counter += 1
                continue

            counter -= 1

        return majority
        
