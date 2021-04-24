class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0, curr = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                curr++;
                result = max(result, curr);
            } else {
                curr = 0;
            }
        }
        return result;
    }
};
