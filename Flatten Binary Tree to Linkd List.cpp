/* This is an interesting problem. it is justy pre-order traversal with temp val for node->right
The recursive solutiuon is easy to understand
however the iterative which gives 100% is difficult to understand

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

iterative: 
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->left != NULL) {
                TreeNode* prev = curr->left;
                while(prev->right) {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};


//recrusive solution 

class Solution {
public:
    TreeNode* prev = nullptr;

    void flatten(TreeNode* node) {
        if (node) {
            // Store the right child
            TreeNode* right = node->right;

            // If there's a previous node, make its right point to the current node
            if (prev) {
                prev->right = node;
                prev->left = nullptr; // Ensure left child of prev is null
            }

            // Set current node as the previous node
            prev = node;

            // Recursively flatten the left subtree
            flatten(node->left);

            // Recursively flatten the right subtree
            flatten(right);
        }
    }
};
