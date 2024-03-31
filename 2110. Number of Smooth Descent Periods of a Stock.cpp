//Furthest optimisations
const int init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

#pragma GCC optimize("Ofast")


class Solution {
public:
    int64_t getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int64_t res = n;
        int64_t temp = 0;

        for (int i = 1; i < n; ++i){
            if (prices[i-1] - prices[i] == 1){
                temp++;
                res += temp;
            } else {
                temp = 0;
            }
        }
        return res;
    }
};



//Better solution which just implements gauss in a more efective way (without having to multiply
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = n;
        long long temp = 0;

        for (int i = 1; i < n; ++i){
            if (prices[i-1] - prices[i] == 1){
                temp++;
                res += temp;
            } else {
                temp = 0;
            }
        }
        return res;
    }
};


// My solution using gauss's summation formula
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = n;
        long long sl = 1;

        for (int i = 1; i < n; ++i){
            if (prices[i-1] == prices[i] + 1){
                sl++;
            } else {
                res += (sl * (sl-1)) / 2;
                sl = 1;
            }
        }

        if (sl != 1){
            res += (sl * (sl-1)) / 2;
        }
        return res;
    }
};
