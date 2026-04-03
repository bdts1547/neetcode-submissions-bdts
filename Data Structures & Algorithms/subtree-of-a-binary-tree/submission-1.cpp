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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        // if (!root || !subRoot) return false;
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            if (node->val == subRoot->val && check(node, subRoot)) {
                return true;
            }

            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);

        }

        return false;
    }

    bool check(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot || root->val != subRoot->val) return false;
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }
};
