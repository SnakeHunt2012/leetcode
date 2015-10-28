class Solution {
public:
    int findDuplicate(vector<int>& nums) {
	vector<int> counter(nums.size() - 1, 0);
	for (int i = 0; i < nums.size(); ++i) {
	    if (counter[nums[i] - 1])
		return nums[i];
	    counter[nums[i] - 1] = 1;
	}
	return -1;
    }
};
