class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int size = matrix.size() * matrix[0].size();
        int left = 0, right = matrix[0].size()-1;
        int top = 0, bottom = matrix.size()-1;
        while (result.size() < size) {
            int i = left;
            while (i <= right && result.size() < size) {
                result.push_back(matrix[top][i]);
                i++;
            }
            top++;
            i = top;
            while (i <= bottom && result.size() < size) {
                result.push_back(matrix[i][right]);
                i++;
            }
            right--;
            i = right;
            while (i >= left && result.size() < size) {
                result.push_back(matrix[bottom][i]);
                i--;
            }
            bottom--;
            i = bottom;
            while (i >= top && result.size() < size) {
                result.push_back(matrix[i][left]);
                i--;
            }
            left++;
        }
        return result;
    }
};
