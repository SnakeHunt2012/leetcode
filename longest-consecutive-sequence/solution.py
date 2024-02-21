class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        nums_set = set(nums)

        max_length = 0
        for number in nums:
            if number - 1 not in nums_set:
                current_number = number
                current_length = 1
                while current_number + 1 in nums_set:
                    current_number += 1
                    current_length += 1
                max_length = max(current_length, max_length)

        return max_length
