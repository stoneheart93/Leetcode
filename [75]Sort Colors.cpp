//Given an array nums with n objects colored red, white, or blue, sort them in-p
//lace so that objects of the same color are adjacent, with the colors in the orde
//r red, white, and blue. 
//
// We will use the integers 0, 1, and 2 to represent the color red, white, and b
//lue, respectively. 
//
// You must solve this problem without using the library's sort function. 
//
// 
// Example 1: 
// Input: nums = [2,0,2,1,1,0]
//Output: [0,0,1,1,2,2]
// Example 2: 
// Input: nums = [2,0,1]
//Output: [0,1,2]
// Example 3: 
// Input: nums = [0]
//Output: [0]
// Example 4: 
// Input: nums = [1]
//Output: [1]
// 
// 
// Constraints: 
//
// 
// n == nums.length 
// 1 <= n <= 300 
// nums[i] is 0, 1, or 2. 
// 
//
// 
// Follow up: Could you come up with a one-pass algorithm using only constant ex
//tra space? 
// Related Topics Array Two Pointers Sort 
// 👍 5592 👎 313


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    void sortColors(vector<int>& a)
    {
        int low = 0, mid = 0, high = a.size() - 1;
        while(mid <= high)
        {
            switch(a[mid])
            {
                case 0: swap(a[low++], a[mid++]);
                        break;
                case 1: mid++;
                        break;
                case 2: swap(a[mid], a[high--]);
                        break;
            }
        }
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
