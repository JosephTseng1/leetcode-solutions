class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> curr;
        helper(results, curr, nums, 0);
        return results;
    }
    
    void helper(vector<vector<int>>& results, vector<int> curr, vector<int> nums, int index) {
        results.push_back(curr);
        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            helper(results, curr, nums, i+1);
            curr.pop_back();
        }
    }
};
