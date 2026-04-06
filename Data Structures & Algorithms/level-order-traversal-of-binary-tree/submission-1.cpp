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
    map<int, vector<int>> m;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        res.push_back(vector<int> {root->val});
        int depth = 1;
        travel(root, depth);
        for (auto [k, v]: m) {
            // printf("%d\n", k);
            // for (auto num: v) {
                // printf("%d ", num);
                res.push_back(v);
            // }
        }
        return res;
    }
    void travel(TreeNode* node, int depth) {
        vector<int> res;
        if (!node) return ;
        if (node->left) m[depth].push_back(node->left->val);
        if (node->right) m[depth].push_back(node->right->val);
        travel(node->left, depth + 1);
        travel(node->right, depth + 1);
    }
};
