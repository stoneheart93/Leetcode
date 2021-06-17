//Given an array nums of size n, return the majority element. 
//
// The majority element is the element that appears more than ⌊n / 2⌋ times. You
// may assume that the majority element always exists in the array. 
//
// 
// Example 1: 
// Input: nums = [3,2,3]
//Output: 3
// Example 2: 
// Input: nums = [2,2,1,1,1,2,2]
//Output: 2
// 
// 
// Constraints: 
//
// 
// n == nums.length 
// 1 <= n <= 5 * 104 
// -231 <= nums[i] <= 231 - 1 
// 
//
// 
//Follow-up: Could you solve the problem in linear time and in O(1) space? Relat
//ed Topics Array Divide and Conquer Bit Manipulation 
// 👍 5361 👎 267


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int findCandidate(vector<int>& a)
    {
        int majority_element = a[0];
        int count = 1;

        for(int i = 1; i < a.size(); i++)
        {
            if(a[i] == majority_element)
                count++;
            else
                count--;

            if(count == 0)
            {
                majority_element = a[i];
                count = 1;
            }
        }

        return majority_element;
    }

public:
    int majorityElement(vector<int>& a)
    {
        int cand = findCandidate(a);

        int count = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] == cand)
                count++;
        }

        if(count > a.size()/2)
            return cand;
        else
            return -1;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
