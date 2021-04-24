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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (root == NULL) {
            return results;
        }
        queue<TreeNode*> storage;
        storage.push(root);
        int l = 0;
        while (!storage.empty()) {
            int size = storage.size();
            vector<int> level;
            while (size > 0) {
                TreeNode* temp = storage.front();
                storage.pop();
                size--;
                level.push_back(temp->val);
                if (temp->left) {
                    storage.push(temp->left);
                }
                if (temp->right) {
                    storage.push(temp->right);
                }
            }
            if (l % 2) {
                reverse(level.begin(), level.end());
            }
            results.push_back(level);
            l++;
        }
        return results;
    }
};
