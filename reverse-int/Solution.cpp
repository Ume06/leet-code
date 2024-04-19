#include <climits>
using namespace std;

class Solution {
public:
    // Reverse digits of a signed 32-bit integer
    // Return 0 if reversal causes overflow
    int reverse(int x) {
        long reversed = 0;
        int remainder;

        // Iterate through digits of input, checking for overflow
        while (x != 0) {
            remainder = x % 10;
            x /= 10;

            // Check for overflow before concatenating digit
            if ((reversed > INT_MAX / 10) ||
                (reversed == INT_MAX / 10 && remainder > 7) ||
                (reversed < INT_MIN / 10) ||
                (reversed == INT_MIN / 10 && remainder < -8))
                return 0;

            reversed = reversed * 10 + remainder;
        }

        return reversed;
    }

};