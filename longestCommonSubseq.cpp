class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text2.size()+1][text1.size()+1];
    
        for (int i = 0; i <= text2.size(); i++) {
            dp[i][0] = 0;
        }
    
        for (int i = 0; i <= text1.size(); i++) {
            dp[0][i] = 0;
        }
    
        for (int i = 1; i <= text2.size(); i++) {
            for (int j = 1; j <= text1.size(); j++) {
                if (text2[i-1] == text1[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
                        
        return dp[text2.size()][text1.size()];
    }
};
