//Given a string s, sort it in decreasing order based on the frequency of charac
//ters, and return the sorted string. 
//
// 
// Example 1: 
//
// 
//Input: s = "tree"
//Output: "eert"
//Explanation: 'e' appears twice while 'r' and 't' both appear once.
//So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid a
//nswer.
// 
//
// Example 2: 
//
// 
//Input: s = "cccaaa"
//Output: "aaaccc"
//Explanation: Both 'c' and 'a' appear three times, so "aaaccc" is also a valid 
//answer.
//Note that "cacaca" is incorrect, as the same characters must be together.
// 
//
// Example 3: 
//
// 
//Input: s = "Aabb"
//Output: "bbAa"
//Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
//Note that 'A' and 'a' are treated as two different characters.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 5 * 105 
// s consists of English letters and digits. 
// 
// Related Topics Hash Table Heap 
// 👍 2445 👎 151


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static bool compare(pair<int, int> a, pair<int, int> b)
    {
        if(a.second == b.second)
            return (a.first < b.first);
        return (a.second > b.second);
    }

public:
    string frequencySort(string s)
    {
        unordered_map<char, int> hash;
        for(int i = 0; s[i]; i++)
            hash[s[i]]++;

        vector<pair<char, int>> char_count;
        for(auto it = hash.begin(); it != hash.end(); it++)
            char_count.push_back(make_pair(it->first, it->second));

        sort(char_count.begin(), char_count.end(), compare);

        string result = "";
        for(int i = 0; i < char_count.size(); i++)
        {
            while(char_count[i].second--)
                result += char_count[i].first;
        }

        return result;
    }
};

//Time Complexity: O(n + m log m)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
