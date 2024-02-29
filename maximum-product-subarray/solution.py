class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_dp = [nums[0]]
        min_dp = [nums[0]]

        for index in range(1, len(nums)):
            current_val = nums[index]
            max_val = max(current_val, max_dp[-1] * current_val, min_dp[-1] * current_val)
            min_val = min(current_val, max_dp[-1] * current_val, min_dp[-1] * current_val)
            max_dp.append(max_val)
            min_dp.append(min_val)

        return max(max_dp)
