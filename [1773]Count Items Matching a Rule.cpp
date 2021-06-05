//You are given an array items, where each items[i] = [typei, colori, namei] des
//cribes the type, color, and name of the ith item. You are also given a rule repr
//esented by two strings, ruleKey and ruleValue. 
//
// The ith item is said to match the rule if one of the following is true: 
//
// 
// ruleKey == "type" and ruleValue == typei. 
// ruleKey == "color" and ruleValue == colori. 
// ruleKey == "name" and ruleValue == namei. 
// 
//
// Return the number of items that match the given rule. 
//
// 
// Example 1: 
//
// 
//Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phon
//e","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
//Output: 1
//Explanation: There is only one item matching the given rule, which is ["comput
//er","silver","lenovo"].
// 
//
// Example 2: 
//
// 
//Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone
//","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
//Output: 2
//Explanation: There are only two items matching the given rule, which are ["pho
//ne","blue","pixel"] and ["phone","gold","iphone"]. Note that the item ["computer
//","silver","phone"] does not match. 
//
// 
// Constraints: 
//
// 
// 1 <= items.length <= 104 
// 1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10 
// ruleKey is equal to either "type", "color", or "name". 
// All strings consist only of lowercase letters. 
// 
// Related Topics Array String 
// 👍 303 👎 51


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue)
    {
        int count = 0;
        int index;

        for(int i = 0; i < items.size(); i++)
        {
            if(ruleKey == "type")
                index = 0;
            else if(ruleKey == "color")
                index = 1;
            else
                index = 2;

            if(items[i][index] == ruleValue)
                count++;
        }

        return count;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
