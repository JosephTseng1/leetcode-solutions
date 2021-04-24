class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> storage;
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            storage[sorted].push_back(strs[i]);
        }
        for (auto pair: storage) {
            result.push_back(pair.second);
        }
        return result;
    }
};
