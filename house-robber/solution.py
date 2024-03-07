class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return nums[0]

        prev = nums[0]
        last = max(nums[0], nums[1])

        for index in range(2, len(nums)):            
            current = max(last, prev + nums[index])
            prev = last
            last = current

        return last
