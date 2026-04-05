/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // p always less than q
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);

      
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
           
            if (node->val >= p->val && node->val <= q->val) return node;
   
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);

        }
        return root;
    }

};