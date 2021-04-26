class Solution {
public:
    void helper(vector<string> &results, vector<string> combos, string curr, int pos, string digits) {
        if (pos == digits.size()) {
            results.push_back(curr);
            return;
        }
        for (int i = 0; i < combos[digits[pos] - '2'].size(); i++) {
            curr.push_back(combos[digits[pos] - '2'][i]);
            helper(results, combos, curr, pos+1, digits);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if (digits.empty()) return results;
        vector<string> combos = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string curr = "";
        helper(results, combos, curr, 0, digits);
        return results;
    }
};
