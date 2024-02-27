#include <vector>
#include <set>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& M) {
        std::set<int> rows = {};
        std::set<int> cols = {};a

        for (size_t i = 0; i < M.size(); ++i) {
            for (size_t j = 0; j < M[0].size(); ++j) { 
                if (M[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (size_t i = 0; i < M.size(); ++i) {
            for (size_t j = 0; j < M[0].size(); ++j) {
                if (rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
                    M[i][j] = 0;
                }
            }
        }
    }
};
    