class Solution {
public:
    void solve(vector<string> &results, string word, int l, int r, int n) {
        if (word.size() == n*2) {
            results.push_back(word);
            return;
        }
        if (l < n) {
            solve(results, word + "(", l+1, r, n);
        }
        if (r < l) {
            solve(results, word + ")", l, r+1, n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string word = "";
        solve(results, word, 0, 0, n);
        return results;
    }
};
