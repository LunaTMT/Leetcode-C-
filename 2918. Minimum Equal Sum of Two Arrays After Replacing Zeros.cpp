//This solution is absolutely disgusting
// beats 100% with optimisation

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        double n1 = 0;
        double n2 = 0;
        
        bool n1_0 = false;
        bool n2_0 = false;
        
        for (int n : nums1){
            n1 += n? n : 1;
            if (n == 0)
                n1_0 = true;
        }

        for (int n : nums2){
            n2 += n? n : 1;
            if (n == 0)
                n2_0 = true;
        }

        if ((!n2_0 && n2 < n1) || (!n1_0 && n1 < n2))
            return -1;

        return n1 < n2? n2 : n1;
    }
};

//Or a shortened way to for bool and int: 

class Solution {
public:
    std::pair<long long, bool> calculateValues(const std::vector<int>& nums) {
        long long sum = 0;
        bool hasZero = false;
        for (int n : nums) {
            sum += (n ? n : 1);
            if (n == 0)
                hasZero = true;
        }
        return std::make_pair(sum, hasZero);
    }

    long long minSum(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        auto [n1, n1_0] = calculateValues(nums1);
        auto [n2, n2_0] = calculateValues(nums2);

        if ((!n2_0 && n2 < n1) || (!n1_0 && n1 < n2))
            return -1;

        return n1 < n2 ? n2 : n1;
    }
};
