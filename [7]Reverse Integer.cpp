//Given a signed 32-bit integer x, return x with its digits reversed. If reversi
//ng x causes the value to go outside the signed 32-bit integer range [-231, 231 -
// 1], then return 0. 
//
// Assume the environment does not allow you to store 64-bit integers (signed or
// unsigned). 
//
// 
// Example 1: 
// Input: x = 123
//Output: 321
// Example 2: 
// Input: x = -123
//Output: -321
// Example 3: 
// Input: x = 120
//Output: 21
// Example 4: 
// Input: x = 0
//Output: 0
// 
// 
// Constraints: 
//
// 
// -231 <= x <= 231 - 1 
// 
// Related Topics Math 
// 👍 4855 👎 7391


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reverse(int num)
    {
        int reversed_num = 0;

        while(num != 0)
        {
            int rem = num % 10;

            if(reversed_num == INT_MAX/10 && rem > 7 || reversed_num > INT_MAX/10)
                return 0;
            if(reversed_num == INT_MIN/10 && rem < -8 || reversed_num < INT_MIN/10)
                return 0;

            reversed_num = (reversed_num * 10) + rem;
            num = num / 10;
        }

        return reversed_num;
    }
};

//Time Complexity: O(n), where n is the no of digits of num
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
