class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if (root == nullptr)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int rightVal;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                rightVal = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(rightVal);
        }
        return res;
    }
};
