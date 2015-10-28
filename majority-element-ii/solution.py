class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def majorityElement(self, nums):

        major_one = None
        major_two = None

        counter_one = 0
        counter_two = 0

        for number in nums:
            if major_one == number or major_one is None:
                major_one = number
                counter_one += 1
                continue
            
            if major_two == number or major_two is None:
                major_two = number
                counter_two += 1
                continue

            if counter_one == 0:
                major_one = number
                counter_one += 1
                continue
        
            if counter_two == 0:
                major_two = number
                counter_two += 1
                continue

            counter_one -= 1
            counter_two -= 1

        counter_one = 0
        counter_two = 0
        
        for number in nums:
            if major_one == number:
                counter_one += 1
                continue
            
            if major_two == number:
                counter_two += 1
                continue

        result = []
        if counter_one > len(nums) / 3:
            result.append(major_one)
        if counter_two > len(nums) / 3:
            result.append(major_two)

        return result

