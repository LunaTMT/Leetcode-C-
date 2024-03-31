class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int last_group = groups[0];
        res.push_back(words[0]);

        for(int i=1; i<words.size(); ++i){
            if (last_group != groups[i]){
                last_group = groups[i];
                res.push_back(words[i]);
            }
        }

        return res;
    }
};
