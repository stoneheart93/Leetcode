//Given two stings ransomNote and magazine, return true if ransomNote can be
//constructed from magazine and false otherwise.
//
// Each letter in magazine can only be used once in ransomNote. 
//
// 
// Example 1: 
// Input: ransomNote = "a", magazine = "b"
//Output: false
// Example 2: 
// Input: ransomNote = "aa", magazine = "ab"
//Output: false
// Example 3: 
// Input: ransomNote = "aa", magazine = "aab"
//Output: true
// 
// 
// Constraints: 
//
// 
// 1 <= ransomNote.length, magazine.length <= 105 
// ransomNote and magazine consist of lowercase English letters. 
// 
// Related Topics String 
// 👍 925 👎 245


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> hash;
        for(int i = 0; i < ransomNote.size(); i++)
            hash[ransomNote[i]]++;

        for(int i = 0; i < magazine.size(); i++)
        {
            if(hash.find(magazine[i]) != hash.end())
            {
                hash[magazine[i]]--;
                if(hash[magazine[i]] == 0)
                    hash.erase(magazine[i]);
            }
        }

        return (hash.size() == 0);
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
