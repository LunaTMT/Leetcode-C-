class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int n = nums.size();
        int i = n-1;
        unordered_set<int> seen = {};

        while (i >= 0 && seen.size() != k){
            auto it = seen.find(nums[i]);

            if (nums[i] <= k && it == seen.end()){
                seen.insert(nums[i]);
            }
            i--;
        }
        
        return n-i-1;
    }
};


// Also a very good solution:

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt[51] = {};
        int i = nums.size()-1;
        for (int found = 0; found < k; --i){
            if (nums[i] <= k){
                found += (cnt[nums[i]]++ == 0);
            }
        }
        return nums.size() - i - 1;
    }
};

