class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates = sorted(candidates)

        def generate(candidates: List[int], target: int) -> List[List[int]]:
            res_list = []
            for index in range(len(candidates)):
                select_value = candidates[index]
                remain_target = target - select_value
                remain_list = candidates[index:]
                if remain_target > 0:
                    res_list += [[select_value] + res for res in generate(remain_list, remain_target)]
                elif remain_target == 0:
                    res_list.append([select_value])
                else:
                    pass

            return res_list
        
        return generate(candidates, target)
