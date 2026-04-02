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
    int longestPath = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        findDepth(root);
        return longestPath;
    }

    int findDepth(TreeNode* node) {
        if (!node) return 0;
        int left  = findDepth(node->left);
        int right = findDepth(node->right);
        longestPath = max(longestPath, left + right);
        return 1 + max(left, right); 
    }
};
