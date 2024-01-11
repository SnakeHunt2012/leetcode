class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_index = 0
        for index in range(len(nums)):
            if index > max_index:
                return False
            else:
                max_index = max(max_index, index + nums[index])
                if max_index >= len(nums) - 1:
                    return True
