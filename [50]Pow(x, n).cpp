//Implement pow(x, n), which calculates x raised to the power n (i.e., xn). 
//
// 
// Example 1: 
//
// 
//Input: x = 2.00000, n = 10
//Output: 1024.00000
// 
//
// Example 2: 
//
// 
//Input: x = 2.10000, n = 3
//Output: 9.26100
// 
//
// Example 3: 
//
// 
//Input: x = 2.00000, n = -2
//Output: 0.25000
//Explanation: 2-2 = 1/22 = 1/4 = 0.25
// 
//
// 
// Constraints: 
//
// 
// -100.0 < x < 100.0 
// -231 <= n <= 231-1 
// -104 <= xn <= 104 
// 
// Related Topics Math Binary Search 
// 👍 2466 👎 3867


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int y)
    {
        if(y == 0)
            return 1;
        if(y == 1)
            return x;
        if(y == -1)
            return 1/x;

        double cache = myPow(x, y/2);

        if(y % 2 == 0)
            return cache * cache;
        else
        {
            if(y < 0)
                return 1/x * cache * cache;
            else
                return x * cache * cache;
        }
    }
};

//Time Complexity: O(log x)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
