//Given a sentence text (A sentence is a string of space-separated words) in the
// following format: 
//
// 
// First letter is in upper case. 
// Each word in text are separated by a single space. 
// 
//
// Your task is to rearrange the words in text such that all words are rearrange
//d in an increasing order of their lengths. If two words have the same length, ar
//range them in their original order. 
//
// Return the new text following the format shown above. 
//
// 
// Example 1: 
//
// 
//Input: text = "Leetcode is cool"
//Output: "Is cool leetcode"
//Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "
//cool" of length 4.
//Output is ordered by length and the new first word starts with capital letter.
//
// 
//
// Example 2: 
//
// 
//Input: text = "Keep calm and code on"
//Output: "On and keep calm code"
//Explanation: Output is ordered as follows:
//"On" 2 letters.
//"and" 3 letters.
//"keep" 4 letters in case of tie order by position in original text.
//"calm" 4 letters.
//"code" 4 letters.
// 
//
// Example 3: 
//
// 
//Input: text = "To be or not to be"
//Output: "To be or to be not"
// 
//
// 
// Constraints: 
//
// 
// text begins with a capital letter and then contains lowercase letters and sin
//gle space between words. 
// 1 <= text.length <= 10^5 
// 
// Related Topics String Sort 
// 👍 313 👎 55


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<string> strsplit(string word, char delim)
    {
        vector<string> result;

        stringstream s(word);
        while(s.good())
        {
            string temp;
            getline(s, temp, delim);
            result.push_back(temp);
        }

        return result;
    }

    static bool compare(pair<string, int> a, pair<string, int> b)
    {
        return a.second < b.second;
    }

public:
    string arrangeWords(string text)
    {
        text[0] = tolower(text[0]);
        vector<string> words = strsplit(text, ' ');

        vector<pair<string, int>> str_len;
        for(int i = 0; i < words.size(); i++)
            str_len.push_back({words[i], words[i].size()});

        stable_sort(str_len.begin(), str_len.end(), compare);

        string result = "";
        for(int i = 0; i < str_len.size(); i++)
        {
            if(i == str_len.size() - 1)
                result += str_len[i].first;
            else
                result += str_len[i].first + " ";
        }

        result[0] = toupper(result[0]);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
