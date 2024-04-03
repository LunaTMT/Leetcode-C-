// Brilliant solution 
class Solution {
private:
    void fast_io() const {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
public:
    Solution() {
        fast_io();
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        if (k == n * n) return matrix[n - 1][n - 1];
        if (k == 1) return matrix[0][0];
        
        int L = matrix[0][0], R = matrix[n - 1][n - 1];
        while (L < R) {
            int M = (L + R) >> 1;

            int count = 0;
            for (int i = 0; i < n; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), M) - matrix[i].begin();
            }

            if (count < k) {
                L = M + 1;
            } else {
                R = M;
            }
        }

        return R;
    }
};



// easier heap sol
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        priority_queue<int> maxHeap;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                maxHeap.push(matrix[i][j]);
                if (maxHeap.size() > k) maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};
