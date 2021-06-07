//International Morse Code defines a standard encoding where each letter is mapp
//ed to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-.
//..", "c" maps to "-.-.", and so on. 
//
// For convenience, the full table for the 26 letters of the English alphabet is
// given below: 
//
// 
//[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--
//","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.
//."] 
//
// Now, given a list of words, each word can be written as a concatenation of th
//e Morse code of each letter. For example, "cab" can be written as "-.-..--...", 
//(which is the concatenation "-.-." + ".-" + "-..."). We'll call such a concatena
//tion, the transformation of a word. 
//
// Return the number of different transformations among all words we have. 
//
// 
//Example:
//Input: words = ["gin", "zen", "gig", "msg"]
//Output: 2
//Explanation: 
//The transformation of each word is:
//"gin" -> "--...-."
//"zen" -> "--...-."
//"gig" -> "--...--."
//"msg" -> "--...--."
//
//There are 2 different transformations, "--...-." and "--...--.".
// 
//
// Note: 
//
// 
// The length of words will be at most 100. 
// Each words[i] will have length in range [1, 12]. 
// words[i] will only consist of lowercase letters. 
// 
// Related Topics String 
// 👍 942 👎 863


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<string> alphabetToMorse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        unordered_set<string> hash;
        for(int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            string transformed_word = "";
            for(int j = 0; j < word.size(); j++)
                transformed_word += alphabetToMorse[word[j] - 'a'];

            hash.insert(transformed_word);
        }

        return hash.size();
    }
};

//Time Complexity: O(nm)
//Space Complexity: O(nm)

//leetcode submit region end(Prohibit modification and deletion)
