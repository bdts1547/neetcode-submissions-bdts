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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        if (p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        // stack<TreeNode*> stk;
        // stk.push(p);
        // stk.push(q);
        // while (!stk.empty()) {
        //     TreeNode* pNode = stk.top();
        //     TreeNode *qNode = stk.top();
        //     stk.pop(); stk.pop();

        //     if (pNode->val != qNode->val) return false;
        //     if (!pNode ->left || !qNode->left) {
        //         stk.push(pNode->left);
        //         stk.push(qNode->left);
        //     }
        //     if (!pNode ->right || !qNode->right) {
        //         stk.push(pNode->right);
        //         stk.push(qNode->right);
        //     }

        // }
        // return true;
    }
};
