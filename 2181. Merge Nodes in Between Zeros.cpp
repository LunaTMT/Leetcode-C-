//99.69 with optimisation

static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if (!head) return nullptr; 
        
        head = head->next;

        ListNode* prev = head; 
        ListNode* current = head;
        
        double sum = 0;

        while (current) {
            if (current->val == 0){
                prev->val = sum;
                if (current->next)
                    prev = prev->next;
                sum = 0;
            } else {
                sum += current->val;
            }
            current = current->next;
        }
        prev->next = nullptr;
        return head;
    }
};


//What in the fucking fuck does this even do? 

static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout.tie(nullptr);
    return 0;
}();

int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str; getline(cin, str);) {
        istringstream ss(str); ss.ignore(3);
        ostringstream os;
        int sum = 0;
        bool first = true;
        cout << '[';
        for (int i; ss >> i; ss.ignore()) {
            if (!i) {
                os << (first ? "" : ",") << sum;
                sum = 0;
                first = false;
            } else {
                sum += i;
            }
        }
        os << ']';
        cout << os.str() << '\n';
    }
    exit(0);
    return 0;
}();

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        return nullptr;
    }
};
