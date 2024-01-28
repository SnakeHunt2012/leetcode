class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 1:
            return nums
        length = len(nums)

        i = length - 2
        while i >= 0:
            if nums[i] < nums[i + 1]:
                break
            i -= 1

        if i < 0:
            nums.reverse()
            return nums

        j = length - 1
        while j > i + 1:
            if nums[j] > nums[i]:
                break
            j -= 1

        nums[i], nums[j] = nums[j], nums[i]

        self.sort(nums, i + 1, length - 1)
        return nums

    def sort(self, nums, left, right):
        if right - left < 1:
            return
        mid = self.partition(nums, left, right)
        self.sort(nums, left, mid - 1)
        self.sort(nums, mid + 1, right)

    def partition(self, nums, left, right):
        pivot = nums[right]
        i = left
        j = left
        while j < right:
            if nums[j] < nums[right]:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
            j += 1
        nums[i], nums[j] = nums[j], nums[i]
        return i

