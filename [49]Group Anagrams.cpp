//Given an array of strings strs, group the anagrams together. You can return th
//e answer in any order. 
//
// An Anagram is a word or phrase formed by rearranging the letters of a differe
//nt word or phrase, typically using all the original letters exactly once. 
//
// 
// Example 1: 
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2: 
// Input: strs = [""]
//Output: [[""]]
// Example 3: 
// Input: strs = ["a"]
//Output: [["a"]]
// 
// 
// Constraints: 
//
// 
// 1 <= strs.length <= 104 
// 0 <= strs[i].length <= 100 
// strs[i] consists of lower-case English letters. 
// 
// Related Topics Hash Table String 
// 👍 5615 👎 238


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> hash;

        for(int i = 0; i < strs.size(); i++)
        {
            string word = strs[i];

            vector<int> count(26, 0);
            for(int i = 0; word[i]; i++)
                count[word[i] - 'a']++;
            string key = "";
            for(int i = 0; i < 26; i++)
                key += to_string(count[i]) + '#';

            hash[key].push_back(word);
        }

        vector<vector<string>> result;
        for(auto it = hash.begin(); it != hash.end(); it++)
            result.push_back(it->second);
        return result;
    }
};

//Time Complexity: O(nm), where n is the size of strs and m is the maximum size of a string in strs
//Space Complexity: O(nm)

//leetcode submit region end(Prohibit modification and deletion)
