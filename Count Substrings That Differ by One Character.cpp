//Wtf????

#include <string>
#include <vector>
#include <iostream>  // Include this for std::cout

using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0;
        for (int i = 0; i < s.length(); ++i)
            res += helper(s, t, i, 0);
        for (int j = 1; j < t.length(); ++j)
            res += helper(s, t, 0, j);
        return res;
    }

private:
    int helper(string s, string t, int i, int j) {
        int res = 0, pre = 0, cur = 0;
        for (int n = s.length(), m = t.length(); i < n && j < m; ++i, ++j) {
            cur++;
            if (s[i] != t[j])
                pre = cur, cur = 0;
            res += pre;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int result = sol.countSubstrings("aba", "baba");
    cout << "Number of substrings: " << result << endl;  // Print the result
    return 0;
}
