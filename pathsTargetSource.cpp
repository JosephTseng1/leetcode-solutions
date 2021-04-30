class Solution {
public:
    void helper(vector<vector<int>> &results, vector<vector<int>>& graph, vector<int> path) {
        int n = path.size(), target = graph.size()-1;
        int num = path[n-1];
        if (path[n-1] == target) {
            results.push_back(path);
            return;
        }
        for (int i = 0; i < graph[num].size(); i++) {
            path.push_back(graph[num][i]);
            helper(results, graph, path);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> results;
        vector<int> path = {0};
        helper(results, graph, path);
        return results;
    }
};
