class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long low = 1;
        long high = 2 * (int)1e9;
        long ab = long(a)*long(b)/__gcd(long(a), long(b));
        long ac = long(a)*long(c)/__gcd(long(a), long(c));
        long bc = long(b)*long(c)/__gcd(long(b), long(c));
        long abc = long(a)*bc/__gcd(long(a), bc);
        while (low < high) {
            long mid = (low + high)/2;
            long long int numOfUgly = (mid/a + mid/b + mid/c) - (mid/ab + mid/ac + mid/bc) + mid/abc;
            if (numOfUgly >= n) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        return int(low);
    }
};
