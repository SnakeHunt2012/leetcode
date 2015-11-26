/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index_map;
        vector<int> index_vec;
        for (int iter = 0; iter < nums.size(); ++iter) {
            cout << target - nums[iter] << endl;
            if (index_map.find(target - nums[iter]) != index_map.end()) {
                index_vec.push_back(index_map[target - nums[iter]]);
                index_vec.push_back(iter + 1);
                return index_vec;
            } else {
                index_map[nums[iter]] = iter + 1;
            }
        }
    }
};
