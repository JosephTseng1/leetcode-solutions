class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int currMax = nums[0];
        int result = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            currMax = max(nums[i], nums[i]+currMax);
            result = max(currMax, result);
        }
        return result;
    }
};
