//Given a string s, reverse only all the vowels in the string and return it. 
//
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases
//. 
//
// 
// Example 1: 
// Input: s = "hello"
//Output: "holle"
// Example 2: 
// Input: s = "leetcode"
//Output: "leotcede"
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 3 * 105 
// s consist of printable ASCII characters. 
// 
// Related Topics Two Pointers String 
// 👍 1086 👎 1521


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    bool isvowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    void swap(char& a, char& b)
    {
        char temp = a;
        a = b;
        b = temp;
    }

public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            if(!isvowel(s[i]))
            {
                i++;
                continue;
            }
            if(!isvowel(s[j]))
            {
                j--;
                continue;
            }

            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
