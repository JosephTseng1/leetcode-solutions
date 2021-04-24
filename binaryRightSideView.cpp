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
    void helper(vector<int> &results, int &maxDepth, int currDepth, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (currDepth > maxDepth) {
            maxDepth = currDepth;
            results.push_back(root->val);
        }
        helper(results, maxDepth, currDepth+1, root->right);
        helper(results, maxDepth, currDepth+1, root->left);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> results;
        int maxDepth = 0, currDepth = 0;
        helper(results, maxDepth, currDepth+1, root);
        return results;
    }
