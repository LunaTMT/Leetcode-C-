class Solution {
public:
    string simplifyPath(string path) {
        istringstream iss(path);
        vector<string> dir;
        string s;

        while (getline(iss, s, '/')) {
            if (!s.empty()){
                if (s == ".") continue;
                if (s == ".."){
                    if (!dir.empty())
                        dir.pop_back();
                } else {
                    dir.push_back(s);
                }
            }      
        }

        string res = "/";
        for (string s : dir){
            res += (s + "/");
        }
        if (!dir.empty())
            res.pop_back();

        return res;
    }
};
