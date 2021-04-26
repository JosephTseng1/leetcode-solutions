class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }
        int max = 1;
        int start = 0;
        int n = s.size();
        bool dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dp[i][j] = true;
                    start = i;
                } else{
                    dp[i][j] = false;
                }
            }
        }
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                max = 2;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = 3; j <= n; j++) {
                int end = i + j - 1;
                if (end < n && s[i] == s[end] && dp[i+1][end-1]) {
                    dp[i][end] = true;
                    if (j > max) {
                        start = i;
                        max = j;
                    }
                }
            }
        }
        return s.substr(start, max);
    }
};
