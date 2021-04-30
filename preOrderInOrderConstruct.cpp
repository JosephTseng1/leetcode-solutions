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
    TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int &root, int l, int r) {
        if (l > r) {
            return NULL;
        }
        int start = l;
        while (inorder[start] != preorder[root]) start++;
        TreeNode* tree = new TreeNode(preorder[root]);
        root++;
        tree->left = helper(preorder, inorder, root, l, start-1);
        tree->right = helper(preorder, inorder, root, start+1, r);
        return tree;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root = 0;
        return helper(preorder, inorder, root, 0, preorder.size()-1);
    }
};
