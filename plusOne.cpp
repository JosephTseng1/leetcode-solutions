class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (digits[n-1] == 9) {
            int i = n-1;
            while (i >= 0 && digits[i]+1 > 9) {
                digits[i] = 0;
                i--;
            }
            if (i >= 0) {
                digits[i]++;
            } else {
                digits[0] = 0;
                digits.insert(digits.begin(), 1);
            }
        } else {
            digits[n-1]++;
        }
        return digits;
    }
};
