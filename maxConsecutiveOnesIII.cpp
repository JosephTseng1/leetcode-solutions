class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, zeroes = 0;
        int n = A.size(), result = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                zeroes++;
            }
            while (zeroes > K) {
                if (A[left] == 0) {
                    zeroes--;
                }
                left++;
            }
            result = max(i - left + 1, result);
        }
        return result;
    }
};
