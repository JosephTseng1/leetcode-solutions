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
    pair<int, int> recur(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }
        pair<int, int> left = recur(root->left);
        pair<int, int> right = recur(root->right);
        int rob = root->val + left.second + right.second;
        int notRob = max(left.first, left.second) + max(right.first, right.second);
        return {rob, notRob};
    }
    int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        pair<int, int> ans = recur(root);
        return max(ans.first, ans.second);
    }
};
