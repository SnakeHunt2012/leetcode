class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] > dp[-1]:
                dp.append(nums[i])
            elif nums[i] == dp[-1]:
                continue
            else:
                left, right = 0, len(dp) - 1
                while left <= right:
                    mid = (left + right) // 2
                    if dp[mid] < nums[i]:
                        left = mid + 1
                    else:
                        right = mid - 1
                dp[left] = nums[i]

        return len(dp)
