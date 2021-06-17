//Given a non-negative integer x, compute and return the square root of x. 
//
// Since the return type is an integer, the decimal digits are truncated, and on
//ly the integer part of the result is returned. 
//
// Note: You are not allowed to use any built-in exponent function or operator, 
//such as pow(x, 0.5) or x ** 0.5. 
//
// 
// Example 1: 
//
// 
//Input: x = 4
//Output: 2
// 
//
// Example 2: 
//
// 
//Input: x = 8
//Output: 2
//Explanation: The square root of 8 is 2.82842..., and since the decimal part is
// truncated, 2 is returned. 
//
// 
// Constraints: 
//
// 
// 0 <= x <= 231 - 1 
// 
// Related Topics Math Binary Search 
// 👍 2076 👎 2420


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x)
    {
        if(x == 0 || x == 1)
            return x;

        long int low = 1, high = x / 2;
        int ans = -1;

        while(low <= high)
        {
            long int mid = low + (high - low) / 2;
            long int midsqr = mid * mid;
            if(midsqr == x)
            {
                ans = mid;
                return ans;
            }
            else if(midsqr < x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
