
// One liner
class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
        //😡
    }
};

// DP Solution
class Solution {
public:
    std::vector<int> dp;

    bool can_win(int i) {
        if (i == 1) return false;
        if (dp[i] != -1) return dp[i];
        bool a = false;

        for (int j = 1; j <= i/2; j++) {
            if (i % j == 0) {
                a |= !can_win(i - j);
            }
        }
        return dp[i] = a;
    }

    bool divisorGame(int n) {
        dp.resize(n + 1, -1);
        return can_win(n);
    }
};
