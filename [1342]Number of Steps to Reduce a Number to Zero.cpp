//Given a non-negative integer num, return the number of steps to reduce it to z
//ero. If the current number is even, you have to divide it by 2, otherwise, you h
//ave to subtract 1 from it. 
//
// 
// Example 1: 
//
// 
//Input: num = 14
//Output: 6
//Explanation: 
//Step 1) 14 is even; divide by 2 and obtain 7. 
//Step 2) 7 is odd; subtract 1 and obtain 6.
//Step 3) 6 is even; divide by 2 and obtain 3. 
//Step 4) 3 is odd; subtract 1 and obtain 2. 
//Step 5) 2 is even; divide by 2 and obtain 1. 
//Step 6) 1 is odd; subtract 1 and obtain 0.
// 
//
// Example 2: 
//
// 
//Input: num = 8
//Output: 4
//Explanation: 
//Step 1) 8 is even; divide by 2 and obtain 4. 
//Step 2) 4 is even; divide by 2 and obtain 2. 
//Step 3) 2 is even; divide by 2 and obtain 1. 
//Step 4) 1 is odd; subtract 1 and obtain 0.
// 
//
// Example 3: 
//
// 
//Input: num = 123
//Output: 12
// 
//
// 
// Constraints: 
//
// 
// 0 <= num <= 10^6 
// 
// Related Topics Bit Manipulation 
// 👍 960 👎 89


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfSteps(int num)
    {
        int steps = 0;
        while(num)
        {
            if(num % 2 == 0)
                num = num / 2;
            else
                num--;
            steps++;
        }

        return steps;
    }
};

//Time Complexity: O(n), where n is the no of digits
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
