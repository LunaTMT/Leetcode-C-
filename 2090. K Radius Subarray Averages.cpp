#include <vector>

class Solution {
public:
    std::vector<int> getAverages(std::vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        int range = 2 * k + 1; // Size of the sliding window

        std::vector<int> res(n, -1); // Initialize result array with -1

        if (range > n) // Check if the window size is larger than the array
            return res;
        if (k == 0) // If k is 0, return nums as it is
            return nums;

        double windowSum = 0;

        // Calculate sum for the initial window
        for (int i = 0; i < range; ++i) {
            windowSum += nums[i];
        }

        // Calculate the average for the initial window and store it in the result
        res[k] = static_cast<int>(windowSum / range);

        // Slide the window and calculate averages for subsequent windows
        for (int i = k + 1; i < n - k; ++i) {
            windowSum += nums[i + k];
            windowSum -= nums[i - k - 1];
            res[i] = static_cast<int>(windowSum / range);
        }

        return res;
    }
};
