class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        for (int i = 0; i <= n; i++) {
            dp[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max((i - j) * j, (i - j) * dp[j]));
            }
        }
        return dp[n];
    }
};
