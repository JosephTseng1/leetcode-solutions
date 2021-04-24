class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = amount, c = coins.size();
        int dp[n+1];
        for (int i = 0; i <= n; i++) {
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < c; j++) {
                int result = i - coins[j];
                if (result >= 0 && dp[result] != INT_MAX && dp[result] + 1 < dp[i]) {
                    dp[i] = dp[result] + 1;
                }
            }
        }
        return (dp[n] != INT_MAX) ? dp[n] : -1;
    }
};
