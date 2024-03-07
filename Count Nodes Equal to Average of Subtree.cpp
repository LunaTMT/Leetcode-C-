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
    int ans = 0;
    std::pair<int,int> solve(TreeNode* root){
        if(root==nullptr) return {0,0};
        
        auto left = solve(root->left);
        int l_sum = left.first;
        int l_cnt = left.second;
        
        auto right = solve(root->right);
        int r_sum = right.first;
        int r_cnt = right.second;
        
        int sum = root->val + l_sum + r_sum;
        int cnt = l_cnt + r_cnt + 1;
        
        if(root->val == sum/cnt) ans++;
        return {sum, cnt};
    }
    
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};

int main() {
    std::vector<int> data = {4, 8, 5, 0, 1, INT_MIN, 6};

    TreeNode* root = createTreeFromArray(data);

    Solution sol;

    int result = sol.averageOfSubtree(root);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
