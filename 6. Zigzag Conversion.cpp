
// Good simple solution but It uses O(n) auxillary space. conversion is not done in place.
// Beats 97.74 Runtime

class Solution {
public:
    string convert(string s, int numRows) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        if (numRows == 1){
            return s;
        } 

        string groups[numRows];
        int n = s.length();
        int i = 0;

        while (i < n){
            for (int j=0; j < numRows && i < n; ++i, ++j){
                groups[j] += s[i];
            }
            
            for (int j=numRows-2; j > 0 && i < n; ++i, --j){
                groups[j] += s[i];
            }
        }

        string res;
        for (const string& group : groups){
            res += group;
        }

        return res;
    }
};
