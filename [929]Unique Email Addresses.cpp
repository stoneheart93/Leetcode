//Every valid email consists of a local name and a domain name, separated by the
// '@' sign. Besides lowercase letters, the email may contain one or more '.' or '
//+'. 
//
// 
// For example, in "alice@leetcode.com", "alice" is the local name, and "leetcod
//e.com" is the domain name. 
// 
//
// If you add periods '.' between some characters in the local name part of an e
//mail address, mail sent there will be forwarded to the same address without dots
// in the local name. Note that this rule does not apply to domain names. 
//
// 
// For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the 
//same email address. 
// 
//
// If you add a plus '+' in the local name, everything after the first plus sign
// will be ignored. This allows certain emails to be filtered. Note that this rule
// does not apply to domain names. 
//
// 
// For example, "m.y+name@email.com" will be forwarded to "my@email.com". 
// 
//
// It is possible to use both of these rules at the same time. 
//
// Given an array of strings emails where we send one email to each email[i], re
//turn the number of different addresses that actually receive mails. 
//
// 
// Example 1: 
//
// 
//Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcod
//e.com","testemail+david@lee.tcode.com"]
//Output: 2
//Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually r
//eceive mails.
// 
//
// Example 2: 
//
// 
//Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// 1 <= emails.length <= 100 
// 1 <= emails[i].length <= 100 
// email[i] consist of lowercase English letters, '+', '.' and '@'. 
// Each emails[i] contains exactly one '@' character. 
// All local and domain names are non-empty. 
// Local names do not start with a '+' character. 
// 
// Related Topics String 
// 👍 1201 👎 225


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

    string applyRules(string localName)
    {
        string result = "";
        for(int i = 0; localName[i]; i++)
        {
            if(localName[i] == '.')
                continue;
            if(localName[i] == '+')
                break;
            result += localName[i];
        }

        return result;
    }

public:
    int numUniqueEmails(vector<string>& emails)
    {
        unordered_set<string> hash;

        for(int i = 0; i < emails.size(); i++)
        {
            vector<string> emailSplit = strsplit(emails[i], '@');
            string modifiedLocalName = applyRules(emailSplit[0]);
            string domainName = emailSplit[1];
            hash.insert(modifiedLocalName + '@' + domainName);
        }

        return hash.size();
    }
};

//Time Complexity: O(nm)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
