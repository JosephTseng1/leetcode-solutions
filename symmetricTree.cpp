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
    bool check(TreeNode* rootOne, TreeNode* rootTwo) {
        if (rootOne == NULL && rootTwo == NULL) {
            return true;
        }
        
        if (rootOne && rootTwo && rootOne->val == rootTwo->val) {
            return check(rootOne->left, rootTwo->right) && check(rootOne->right, rootTwo->left);
        }
        
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
         
        if (root && root->left == NULL && root->right == NULL) {
            return true;
        }
        
        if (root->left && root->right) {
            return check(root->left, root->right);
        }
        
        return false;
    }
};
