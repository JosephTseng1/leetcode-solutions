class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> results (n, 1);
        int left = 1, right = 1;
        for (int i = 1; i < n; i++) {
            left *= nums[i-1];
            results[i] *= left;
        }
        for (int i = n - 2; i >= 0; i--) {
            right *= nums[i+1];
            results[i] *= right;
        }
        return results;
    }
};
