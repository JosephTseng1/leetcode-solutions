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
    void helper(TreeNode* root, int targetSum, int &ans) {
        if (root == NULL) {
            return;
        }
        if (root->val == targetSum) {
            ans++;
        }
        helper(root->left, targetSum-root->val, ans);
        helper(root->right, targetSum-root->val, ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0;
        }
        int ans = 0;
        helper(root, targetSum, ans);
        return ans + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
