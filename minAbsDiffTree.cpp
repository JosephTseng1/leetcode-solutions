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
    void inOrder(TreeNode* root, int &minDiff, TreeNode* &prev) {
        if (root) {
            inOrder(root->left, minDiff, prev);
            if (prev) {
                minDiff = min(root->val-prev->val, minDiff);
            }
            prev = root;
            inOrder(root->right, minDiff, prev);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL) return 0;
        int minDiff = INT_MAX;
        TreeNode *prev = NULL;
        inOrder(root, minDiff, prev);
        return minDiff;
    }
};
