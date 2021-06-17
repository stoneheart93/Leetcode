//Given a sorted array of distinct integers and a target value, return the index
// if the target is found. If not, return the index where it would be if it were i
//nserted in order. 
//
// You must write an algorithm with O(log n) runtime complexity. 
//
// 
// Example 1: 
// Input: nums = [1,3,5,6], target = 5
//Output: 2
// Example 2: 
// Input: nums = [1,3,5,6], target = 2
//Output: 1
// Example 3: 
// Input: nums = [1,3,5,6], target = 7
//Output: 4
// Example 4: 
// Input: nums = [1,3,5,6], target = 0
//Output: 0
// Example 5: 
// Input: nums = [1], target = 0
//Output: 0
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 104 
// -104 <= nums[i] <= 104 
// nums contains distinct values sorted in ascending order. 
// -104 <= target <= 104 
// 
// Related Topics Array Binary Search 
// 👍 3693 👎 299


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int searchInsert(vector<int>& a, int target)
    {
        int ans = a.size();
        int low = 0, high = a.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(a[mid] == target)
                return mid;
            else if(a[mid] < target)
                low = mid + 1;
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};

//Time Complexity: O(log n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
