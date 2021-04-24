class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        int a = 2, b = 3, c = 5;
        int x = 0, y = 0, z = 0;
        for (int i = 1; i < n; i++) {
            int minNum = min(min(a, b), c);
            dp[i] = minNum;
            if (minNum == a) {
                x++;
                a = dp[x] * 2;
            }
            if (minNum == b) {
                y++;
                b = dp[y] * 3;
            }
            if (minNum == c) {
                z++;
                c = dp[z] * 5;
            }
        }
        return dp[n-1];
    }
};
