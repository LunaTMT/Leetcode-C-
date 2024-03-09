
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//Recursive DFS Solution
class Solution {
public:
    TreeNode* ans;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (cloned == nullptr) 
            return cloned;
        
        if (cloned->val == target->val) 
            ans = cloned;

        getTargetCopy(original, cloned->left, target);
        getTargetCopy(original, cloned->right, target);

        return ans; 
    }
};


//Iterative BFS Solution
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        std::queue<TreeNode*> Q;
        Q.push(cloned);

        while (!Q.empty()) {
            TreeNode* current = Q.front();
            Q.pop();

            if (current == nullptr) 
                continue;  
        
            if (current->val == target->val) 
                return current;

            Q.push(current->left);
            Q.push(current->right);
        }
        return nullptr;  
    }
};


// For some reason using a lambda function with capture can increase speed as well as the first three lines where tie and sync is used
// Not 100% sure why but this got me 99.67%
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        TreeNode* res = NULL;
        auto help = [&](TreeNode* original, TreeNode* cloned, TreeNode* target, auto &&help){
            if(original == NULL){
                return ;
            }
            if(original==target){
                res = cloned;
                return;
            }
            help(original->left,cloned->left,target,help);
            help(original->right,cloned->right,target,help);
        return;
        };
        help(original,cloned,target,help);
    return res;
    }
};



int main() {
    return 0;
}