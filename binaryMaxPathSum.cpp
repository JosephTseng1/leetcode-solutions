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
    int path(TreeNode* root, int &maxSum) {
        if (root == NULL) {
            return 0;
        }
        int l = max(path(root->left, maxSum), 0);
        int r = max(path(root->right, maxSum), 0);
        maxSum = max(maxSum, root->val + l + r);
        return root->val + max(l, r);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        if (root == NULL) {
            return 0;
        }
        path(root, maxSum);
        return maxSum;
    }
};
