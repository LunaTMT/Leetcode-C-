class Solution {
public:
    int tribonacci(int n) {
        vector<int> F;
        F.push_back(0);
        F.push_back(1);
        F.push_back(1);
        for (int i=3; i<=n; ++i){
            F.push_back(F[i-1] + F[i-2] + F[i-3]);
        }
        return F[n];
    }
};
