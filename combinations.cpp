class Solution {
public:
    void backTracking(int l, int n, int k, vector<vector<int>> &results, vector<int> &curr) {
        if (curr.size() == k) {
            results.push_back(curr);
            return;
        }
        for (int i = l; i <= n; i++) {
            curr.push_back(i);
            backTracking(i+1, n, k, results, curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> curr;
        backTracking(1, n, k, results, curr);
        return results;
    }
};
