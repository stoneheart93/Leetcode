//Given an array nums of distinct integers, return all the possible permutations
//. You can return the answer in any order. 
//
// 
// Example 1: 
// Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2: 
// Input: nums = [0,1]
//Output: [[0,1],[1,0]]
// Example 3: 
// Input: nums = [1]
//Output: [[1]]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// All the integers of nums are unique. 
// 
// Related Topics Backtracking 
// 👍 6338 👎 138


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void permuteUtil(vector<int>& a, int index, vector<vector<int>>& result)
    {
        if(index == a.size())
            result.push_back(a);
        else
        {
            for(int i = index; i < a.size(); i++)
            {
                swap(a[index], a[i]);
                permuteUtil(a, index + 1, result);
                swap(a[index], a[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& a)
    {
        vector<vector<int>> result;
        permuteUtil(a, 0, result);
        return result;
    }
};

//Time Complexity: O(n!*n^2)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
