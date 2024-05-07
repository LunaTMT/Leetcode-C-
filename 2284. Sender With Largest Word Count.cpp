static int speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> count;

        for(int i = 0; i < senders.size(); ++i) {
            int cnt = 1;
            for (const char c : messages[i]) 
                if (c == ' ')
                    cnt++;
            count[senders[i]] += cnt;
        }
 
        string ans;
        int MAX = INT_MIN;
        for (auto& it : count) {
            if (it.second > MAX || (it.second == MAX && it.first > ans)) {
                ans = it.first;
                MAX = it.second;
            }
        }

        return ans;
    }
};
