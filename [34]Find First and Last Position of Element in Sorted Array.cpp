//Given an array of integers nums sorted in ascending order, find the starting a
//nd ending position of a given target value. 
//
// If target is not found in the array, return [-1, -1]. 
//
// You must write an algorithm with O(log n) runtime complexity. 
//
// 
// Example 1: 
// Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
// Example 2: 
// Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]
// Example 3: 
// Input: nums = [], target = 0
//Output: [-1,-1]
// 
// 
// Constraints: 
//
// 
// 0 <= nums.length <= 105 
// -109 <= nums[i] <= 109 
// nums is a non-decreasing array. 
// -109 <= target <= 109 
// 
// Related Topics Array Binary Search 
// 👍 5860 👎 210


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int firstOccurence(const vector<int>& a, int target)
    {
        int low = 0, high = a.size() - 1;
        int first = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(a[mid] == target)
            {
                first = mid;
                high = mid - 1;
            }
            else if(target < a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        return first;
    }

    int lastOccurence(const vector<int>& a, int target)
    {
        int low = 0, high = a.size() - 1;
        int last = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(a[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }
            else if(target < a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        return last;
    }

public:
    vector<int> searchRange(vector<int>& a, int target)
    {
        int first = firstOccurence(a, target);
        int last = lastOccurence(a, target);

        vector<int> result{first, last};
        return result;
    }
};

//Time Complexity: O(n log n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
