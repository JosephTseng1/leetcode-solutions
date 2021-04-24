class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        int n = nums.size();
        int dp[n];
        dp[start] = nums[start];
        dp[start+1] = max(nums[start+1], nums[start]);
        for (int i = start+2; i <= end; i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        return max(helper(nums, 0, n-2), helper(nums, 1, n-1));
    }
};
