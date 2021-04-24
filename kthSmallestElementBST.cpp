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
    void traversal(TreeNode* root, int &curr, int k, int &ans) {
        if (root) {
            traversal(root->left, curr, k, ans);
            curr++;
            if (curr == k) {
                ans = root->val;
                return;
            }
            traversal(root->right, curr, k, ans);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = root->val, curr = 0;
        traversal(root, curr, k, ans);
        return ans;
    }
};
