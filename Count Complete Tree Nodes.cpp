
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    int count = 0;
    int countNodes(TreeNode* node) {
        if (!node)
            return 0;
        count++;
        countNodes(node->left);
        countNodes(node->right);
        return count;
    }
};



int main() {
    return 0;
}