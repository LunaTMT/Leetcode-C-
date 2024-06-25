const char optimize = []() {std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); return 'c';}();

class Solution {
public:
    struct TrieNode {
        TrieNode* children[26]; 
        bool isLeaf;
    };

    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* curr = root;
        
        for (const char& c : word) {
            int i = c - 'a';
            if (curr->children[i] == nullptr) 
                curr->children[i] = new TrieNode();
            curr = curr->children[i];
        }
        curr->isLeaf = true;
    }

    string search(string word) {
        TrieNode* curr = root;
        
        string prefix;
        for (const char& c : word) {
            int i = c - 'a';
            if (curr->children[i] == nullptr) 
                break;
            
            curr = curr->children[i];
            prefix.push_back(c);
            if (curr->isLeaf) {
                return prefix;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        // Insert all dictionary words into the Trie
        for (const string& word : dictionary) {
            insert(word);
        }

        // Split the sentence into words and replace them
        string res = "";
        istringstream iss(sentence);
        string word;
        
        while (iss >> word) {
            if (!res.empty()) {
                res += " ";
            }
            res += search(word);
        }
        return res;
    }
};
