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

    int total = 0;

    int rangeSumBST(TreeNode* node, int low, int high) {
        
        if (node) {
            rangeSumBST(node->left, low, high);
            if (node->val >= low && node->val <= high) 
                total += node->val;
            rangeSumBST(node->right, low, high);
        }
    
        return total;
    }
};
