class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0:
            return [[]]

        tail_item = nums[-1]
        pre_subset = self.subsets(nums[:-1])
        return pre_subset + [set_item + [tail_item] for set_item in pre_subset]
