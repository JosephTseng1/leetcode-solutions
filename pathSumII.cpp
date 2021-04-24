/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<vector<int>> &results, vector<int> curr, int sum, int currSum) {
        if (root == NULL) {
            return;
        }
        currSum += root->val;
        curr.push_back(root->val);
        if (currSum == sum && root->left == NULL && root->right == NULL) {
            results.push_back(curr);
            return;
        }
        solve(root->left, results, curr, sum, currSum);
        solve(root->right, results, curr, sum, currSum);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> results;
        vector<int> curr;
        solve(root, results, curr, sum, 0);
        return results;
    }
};
