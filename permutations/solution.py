class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        cache = dict()

        def permute(nums: List[int]) -> List[List[int]]:
            if len(nums) == 1:
                return [nums]

            key = " ".join(str(value) for value in sorted(nums))
            if key in cache:
                return cache[key]
    
            res_list = []
            for i in range(len(nums)):
                select_value = nums[i]
                res_list += [[select_value] + res for res in permute(nums[:i] + nums[i + 1:])]
                
            cache[key] = res_list
            return res_list

        return permute(nums)
