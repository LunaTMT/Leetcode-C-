// God Tier solution, bit masking
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> d;
        for (auto& e : reservedSeats) {
            int i = e[0], j = e[1];
            d[i] |= 1 << (10 - j);
        }
        int masks[3] = {0b0111100000, 0b0000011110, 0b0001111000};
        int ans = (n - d.size()) * 2;
        for (auto& [_, x] : d) {
            for (int& mask : masks) {
                if ((x & mask) == 0) {
                    x |= mask;
                    ++ans;
                }
            }
        }
        return ans;
    }
};

// my solution
// It is simple and most obious but ugly
class Solution {
private:
    unordered_map<int, vector<int>> mp;
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& A) {
        
        for (const vector<int>& a : A){
            mp[a[0]].push_back(a[1]);
        }

        int res = (n - mp.size()) * 2;

        for (auto r : mp){
            
            vector<bool> contains(11, 0);
            for (int x : r.second){
                contains[x] = 1;
            }

            int families = 0;

            if (!contains[6] && !contains[9] && !contains[7] && !contains[8]){
                families++;
            }

            if (!contains[5] && !contains[2] && !contains[3] && !contains[4]){
                families++;
            }

            if (families == 0 && !contains[4] && !contains[5] && !contains[6] && !contains[7]) {
                families++;
            }

            res += families;
        }

        return res;
    }
};


