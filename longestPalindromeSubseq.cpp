class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }
        int max = 1, start = 0, n = s.size();
        bool dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dp[i][j] = true;
                } else {
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
        for (int k = 3; k <= n; k++) {
            for (int i = 0; i < n-k+1 ; i++) {
                int j = i + k - 1;
                if (dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (k > max) {
                        start = i;
                        max = k;
                    }
                }
            }
        }
        return s.substr(start, max);
    }
};
