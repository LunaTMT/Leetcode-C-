#include <string>
#include <algorithm>
#include <limits>
#include <stdexcept>

using namespace std;


//First solution
class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        
        // Specify std::reverse
        std::reverse(str.begin(), str.end());

        try {
            // Convert string to integer
            int res = stoi(str);
            
            // Check for overflow or underflow
            if (numeric_limits<int>::min() <= res && res <= numeric_limits<int>::max()) {
                return (x < 0? -res : res);
            } else {
                return 0;
            }
        } catch (const std::out_of_range&) {
            // Handle stoi out_of_range exception
            return 0;
        }
    }
};


//Second best solution
#include <limits>

class Solution {
public:
    int reverse(int x) {
        long r = 0;

        while (x) {
            r = r*10 + x%10;
            x/= 10;
        }

        if (r > INT_MAX || r < INT_MIN) return 0;
        return r;
    }
};

