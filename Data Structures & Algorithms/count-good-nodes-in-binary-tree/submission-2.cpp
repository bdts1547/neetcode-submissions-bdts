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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int cnt = 1;
        dfs(root->val, root->left, cnt);
        dfs(root->val, root->right, cnt);
        // stack<TreeNode*> stk;
        // unordered_map<TreeNode*, int> m;
        // stk.push(root);
        // m[root] = root->val;

        // while (!stk.empty()) {
        //     TreeNode* node = stk.top();
        //     stk.pop();
        //     if (node->val >= m[node]) {
        //         cnt++;
        //     }

        //     if (node->left) {
        //         m[node->left] = max(node->left->val, m[node]);
        //         stk.push(node->left);
        //     }
        //     if (node->right) {
        //         m[node->right] = max(node->right->val, m[node]);
        //         stk.push(node->right);
        //     }


        // }

        
        return cnt;
    }

    void dfs(int max, TreeNode* node, int& cnt) {
        if (!node) return;
        if (node->val >= max) {
            cnt++;
            max = node->val;
        }
        dfs(max, node->left, cnt);
        dfs(max, node->right, cnt);
    }
};
