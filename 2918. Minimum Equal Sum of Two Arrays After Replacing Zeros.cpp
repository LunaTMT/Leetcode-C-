//This solution is absolutely disgusting

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
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

        if (!n1_0 || !n2_0 && n1 != n2)
            if ((!n2_0 && n2 < n1) || (!n1_0 && n1 < n2))
                return -1;

        return n1 < n2? n2 : n1;
    }
};
