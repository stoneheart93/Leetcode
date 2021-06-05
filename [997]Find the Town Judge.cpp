//In a town, there are n people labelled from 1 to n. There is a rumor that one 
//of these people is secretly the town judge. 
//
// If the town judge exists, then: 
//
// 
// The town judge trusts nobody. 
// Everybody (except for the town judge) trusts the town judge. 
// There is exactly one person that satisfies properties 1 and 2. 
// 
//
// You are given trust, an array of pairs trust[i] = [a, b] representing that th
//e person labelled a trusts the person labelled b. 
//
// If the town judge exists and can be identified, return the label of the town 
//judge. Otherwise, return -1. 
//
// 
// Example 1: 
//
// 
//Input: n = 2, trust = [[1,2]]
//Output: 2
// 
//
// Example 2: 
//
// 
//Input: n = 3, trust = [[1,3],[2,3]]
//Output: 3
// 
//
// Example 3: 
//
// 
//Input: n = 3, trust = [[1,3],[2,3],[3,1]]
//Output: -1
// 
//
// Example 4: 
//
// 
//Input: n = 3, trust = [[1,2],[2,3]]
//Output: -1
// 
//
// Example 5: 
//
// 
//Input: n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 1000 
// 0 <= trust.length <= 104 
// trust[i].length == 2 
// trust[i] are all different 
// trust[i][0] != trust[i][1] 
// 1 <= trust[i][0], trust[i][1] <= n 
// 
// Related Topics Graph 
// 👍 1645 👎 134


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<int> trusts(n + 1, 0);
        vector<int> trustedBy(n + 1, 0);

        for(int i = 0; i < trust.size(); i++)
        {
            int a = trust[i][0];
            int b = trust[i][1];
            trusts[a]++;
            trustedBy[b]++;
        }

        for(int i = 1; i <= n; i++)
        {
            if(trusts[i] == 0 && trustedBy[i] == n - 1)
                return i;
        }

        return -1;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
