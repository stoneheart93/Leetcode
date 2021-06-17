//Given a collection of numbers, nums, that might contain duplicates, return all
// possible unique permutations in any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,1,2]
//Output:
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
// Related Topics Backtracking 
// 👍 3138 👎 80


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void permuteUniqueUtil(vector<int>& a, int index, set<vector<int>>& result)
    {
        if(index == a.size())
            result.insert(a);
        else
        {
            for(int i = index; i < a.size(); i++)
            {
                swap(a[index], a[i]);
                permuteUniqueUtil(a, index + 1, result);
                swap(a[index], a[i]);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& a)
    {
        set<vector<int>> temp;
        permuteUniqueUtil(a, 0, temp);

        vector<vector<int>> result(temp.begin(), temp.end());
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
