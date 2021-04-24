class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0, n = nums.size();
        for (int i = 0; i < 32; i++) {
            int sum = 0, mask = (1 << i);
            for (int j = 0; j < n; j++) {
                if ((nums[j] & mask) != 0) {
                    sum++;
                }
            }
            if (sum % 3 == 1) {
                result |= mask;
            }
        }
        return result;
    }
};
