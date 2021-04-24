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
    void helper(int &left, int& maxDepth, int currDepth, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (currDepth > maxDepth) {
            left = root->val;
            maxDepth = currDepth;
        }
        helper(left, maxDepth, currDepth+1, root->left);
        helper(left, maxDepth, currDepth+1, root->right);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int left = root->val, maxDepth = 0, currDepth = 0;
        helper(left, maxDepth, currDepth, root);
        return left;
    }
};
