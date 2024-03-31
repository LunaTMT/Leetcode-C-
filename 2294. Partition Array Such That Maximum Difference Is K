static const auto _ = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int x(0), partitions(1);
        sort(nums.begin(), nums.end());
    
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - nums[x] > k) {
                partitions++;
                x = i;
            }
        }

        return partitions;
    }
};
