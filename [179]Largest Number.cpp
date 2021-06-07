//Given a list of non-negative integers nums, arrange them such that they form t
//he largest number. 
//
// Note: The result may be very large, so you need to return a string instead of
// an integer. 
//
// 
// Example 1: 
//
// 
//Input: nums = [10,2]
//Output: "210"
// 
//
// Example 2: 
//
// 
//Input: nums = [3,30,34,5,9]
//Output: "9534330"
// 
//
// Example 3: 
//
// 
//Input: nums = [1]
//Output: "1"
// 
//
// Example 4: 
//
// 
//Input: nums = [10]
//Output: "10"
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 109 
// 
// Related Topics Sort 
// 👍 3146 👎 326


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static bool compare(string X, string Y)
    {
        string XY = X.append(Y);
        string YX = Y.append(X);
        return XY > YX;
    }
public:
    string largestNumber(vector<int>& a)
    {
        vector<string> nums;
        for(int i = 0; i < a.size(); i++)
            nums.push_back(to_string(a[i]));
        sort(nums.begin(), nums.end(), compare);

        string result = "";
        for(int i = 0; i < nums.size(); i++)
            result += nums[i];

        if(result[0] == '0')
            return "0";
        return result;
    }
};

//Time Complexity: O(n log n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
