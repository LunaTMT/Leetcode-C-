class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;

        if (!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            vector<int> level;
            int level_size = q.size();

            for (int i=0; i < level_size; ++i){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
