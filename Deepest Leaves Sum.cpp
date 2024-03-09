#include <unordered_map>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//Iterative BFS
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int res = 0, i;
        std::queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            for (i = q.size() - 1, res = 0; i >= 0; --i) {
                TreeNode* node = q.front(); q.pop();
                res += node->val;
                if (node->right) q.push(node->right);
                if (node->left)  q.push(node->left);
            }
        }
        return res;
    }
};


/*
// Recursive DFS and unordered_map containing <depth and sum> solution
class Solution {
public:
    std::unordered_map<int, int> depths; 
    int maxDepth = 0;

    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return depths[maxDepth];
    }

    void dfs(TreeNode* node, int currentDepth) {
        if (!node) {
            return;
        }

        if (currentDepth > maxDepth) {
            maxDepth = currentDepth;
        }

        if (depths.find(currentDepth) == depths.end()) {
            depths[currentDepth] = node->val;
        } else {
            depths[currentDepth] += node->val;
        }

        dfs(node->left, currentDepth + 1);
        dfs(node->right, currentDepth + 1);
    }
};
*/


int main() {
        // Create the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    

    Solution solution;
    int result = solution.deepestLeavesSum(root);
    return 0;
}