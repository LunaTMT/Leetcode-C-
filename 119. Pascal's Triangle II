#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
        if (!n) return {1};

        vector<int> current;
        vector<int> res;

        current.push_back(1);
        current.push_back(1);
        n--;
        while (n > 0){
            res.push_back(1);
            for (int i = 0; i < current.size() - 1; ++i){
                res.push_back(current[i] + current[i + 1]);
            }
            res.push_back(1);
            current.swap(res); 
            res.clear();
            n--;
        } 
        return current;
    }
};
