class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> results;
        results.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= results.back()[1]) {
                int c1 = intervals[i][0], c2 = intervals[i][1];
                int b1 = results.back()[0], b2 = results.back()[1];
                results.back()[0] = min(c1, b1);
                results.back()[1] = max(c2, b2);
            } else {
                results.push_back(intervals[i]);
            }
        }
        return results;
    }
};
