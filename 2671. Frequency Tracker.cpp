class FrequencyTracker {
public:
    int cnt[100001] = {};
    int freq[100001] = {};
    
    void add(int n) {
        --freq[cnt[n]];
        ++freq[++cnt[n]];
    }
    
    void deleteOne(int n) {
        if (cnt[n]){
            --freq[cnt[n]];
            ++freq[--cnt[n]];
        }
    }
    
    bool hasFrequency(int f) {
        return freq[f];
    }
};

