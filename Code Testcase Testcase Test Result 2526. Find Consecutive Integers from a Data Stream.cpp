//A very elegant solution, very simple:

static const int _ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
class DataStream
{
private:
    int value_;
    int seen_;
    int max_;

public:
    DataStream(int value, int k) : value_(value), max_(k), seen_(0) {}

    bool consec(int num)
    {
        if(num == value_)
        {
            seen_ = min(max_, seen_ + 1);
            return max_ == seen_;
        }
        else
        {
            seen_ = 0;
            return false;
        }
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
**/



//Queue implementation 
// Most obvious and least challenging implementation, however, least efficient.

#include <iostream>
#include <vector>
using namespace std;

class DataStream {
private:
    int value;
    int k;
    deque<int> dq;
    unordered_map<int, int>cnt;

public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }

    bool consec(int num) {
        cnt[num]++;
        dq.push_back(num);
        bool ans = (cnt.size() == 1 && dq.size() == k && num == value);

        if (dq.size() == k){
            int front = dq.front();
            dq.pop_front();
            cnt[front]--;
            if (cnt[front] == 0){
                cnt.erase(front);
            }
        }
        return ans;
    }
};
