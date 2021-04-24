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
    void getTreePath(TreeNode* root, vector<string> &paths, string path) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            path += to_string(root->val);
            paths.push_back(path);
            return;
        } else {
            path += to_string(root->val) + "->";
        }
        getTreePath(root->left, paths, path);
        getTreePath(root->right, paths, path);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        string result = "";
        getTreePath(root, answer, result);
        return answer;
    }
};
