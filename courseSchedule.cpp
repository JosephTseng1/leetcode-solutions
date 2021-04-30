class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>storage(numCourses, 0);
        stack<int> tracker;
        int count = 0;
        
        for (int i = 0; i < prerequisites.size(); i++) {
            storage[prerequisites[i][0]]++;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (storage[i] == 0) {
                tracker.push(i);
            }
        }
        
        while (!tracker.empty()) {
            count++;
            int num = tracker.top();
            tracker.pop();
            
            for (int i = 0; i < prerequisites.size(); i++) {
                if (prerequisites[i][1] == num) {
                    storage[prerequisites[i][0]]--;
                    
                    if (storage[prerequisites[i][0]] == 0) {
                        tracker.push(prerequisites[i][0]);
                    }
                }
            }
        }
        
        return (count == numCourses);
    }
};
