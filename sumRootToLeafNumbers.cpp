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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int sum = 0;
        dfs(sum, 0, root);
        return sum;
    }
    void dfs(int &sum, int curr, TreeNode* root) {
        curr = (curr * 10) + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += curr;
            return;
        }
        if (root->left) {
            dfs(sum, curr, root->left);
        }
        if (root->right) {
            dfs(sum, curr, root->right);
        }
    }
};
