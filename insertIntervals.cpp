class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> results;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            results.push_back(intervals[i]);
            i++;
        }
        results.push_back(newInterval);
        for (int j = i; j < intervals.size(); j++) {
            if (intervals[j][0] <= results.back()[1]) {
                int c1 = intervals[j][0], c2 = intervals[j][1];
                int b1 = results.back()[0], b2 = results.back()[1];
                results.back()[0] = min(c1, b1);
                results.back()[1] = max(c2, b2);
            } else {
                results.push_back(intervals[j]);
            }
        }
        return results;
    }
};
