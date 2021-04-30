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
    TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int &root, int l, int r) {
        if (l > r) {
            return NULL;
        }
        int start = l;
        while (inorder[start] != postorder[root]) start++;
        TreeNode* tree = new TreeNode(postorder[root]);
        root--;
        tree->right = helper(inorder, postorder, root, start+1, r);
        tree->left = helper(inorder, postorder, root, l, start-1);
        return tree;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int root = inorder.size()-1;
        return helper(inorder, postorder, root, 0, inorder.size()-1);
    }
};
