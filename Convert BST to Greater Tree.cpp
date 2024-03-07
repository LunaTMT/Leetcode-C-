#include <iostream>
#include <queue>
#include <climits>
#include <utility> // Include this header for using pair

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createTreeFromArray(const std::vector<int>& data) {
    if (data.empty()) {
        return nullptr;
    }

    std::queue<TreeNode*> nodesQueue;
    TreeNode* root = new TreeNode(data[0]);
    nodesQueue.push(root);

    for (int i = 1; i < data.size(); i += 2) {
        TreeNode* current = nodesQueue.front();
        nodesQueue.pop();

        if (data[i] != INT_MIN) {
            current->left = new TreeNode(data[i]);
            nodesQueue.push(current->left);
        }

        if (i + 1 < data.size() && data[i + 1] != INT_MIN) {
            current->right = new TreeNode(data[i + 1]);
            nodesQueue.push(current->right);
        }
    }

    return root;
}

class Solution {
    public:
        TreeNode* convertBST(TreeNode* root) {
            int sum = 0;
            reverseInOrderTraversal(root, sum);
            return root;
        }

    private:
        void reverseInOrderTraversal(TreeNode* node, int& sum) {
            if (node) {
                reverseInOrderTraversal(node->right, sum);  // Traverse right subtree
                sum += node->val;                            // Update sum
                node->val = sum;                             // Update node value
                reverseInOrderTraversal(node->left, sum);   // Traverse left subtree
            }
        }
    };


int main() {
    std::vector<int> data = {4, 1, 6, 0, 2, 5, 7, INT_MIN, INT_MIN, INT_MIN, 3, INT_MIN, INT_MIN, INT_MIN, 8};

    TreeNode* root = createTreeFromArray(data);

    Solution sol;

    TreeNode* modifiedRoot = sol.convertBST(root);

    return 0;
}