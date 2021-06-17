//A binary tree is named Even-Odd if it meets the following conditions: 
//
// 
// The root of the binary tree is at level index 0, its children are at level in
//dex 1, their children are at level index 2, etc. 
// For every even-indexed level, all nodes at the level have odd integer values 
//in strictly increasing order (from left to right). 
// For every odd-indexed level, all nodes at the level have even integer values 
//in strictly decreasing order (from left to right). 
// 
//
// Given the root of a binary tree, return true if the binary tree is Even-Odd, 
//otherwise return false. 
//
// 
// Example 1: 
//
// 
//
// 
//Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
//Output: true
//Explanation: The node values on each level are:
//Level 0: [1]
//Level 1: [10,4]
//Level 2: [3,7,9]
//Level 3: [12,8,6,2]
//Since levels 0 and 2 are all odd and increasing, and levels 1 and 3 are all ev
//en and decreasing, the tree is Even-Odd.
// 
//
// Example 2: 
//
// 
//
// 
//Input: root = [5,4,2,3,3,7]
//Output: false
//Explanation: The node values on each level are:
//Level 0: [5]
//Level 1: [4,2]
//Level 2: [3,3,7]
//Node values in the level 2 must be in strictly increasing order, so the tree i
//s not Even-Odd.
// 
//
// Example 3: 
//
// 
//
// 
//Input: root = [5,9,1,3,5,7]
//Output: false
//Explanation: Node values in the level 1 should be even integers.
// 
//
// Example 4: 
//
// 
//Input: root = [1]
//Output: true
// 
//
// Example 5: 
//
// 
//Input: root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
//Output: true
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 105]. 
// 1 <= Node.val <= 106 
// 
// Related Topics Tree 
// 👍 334 👎 25


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root)
    {
        if(root == NULL)
            return false;

        queue<struct TreeNode*> q;
        q.push(root);
        bool evenLevel = true;

        while(1)
        {
            int n = q.size();

            if(n == 0)
                break;

            int evenLast = INT_MIN, oddLast = INT_MAX;
            for(int i = 1; i <= n; i++)
            {
                struct TreeNode* temp = q.front();
                q.pop();

                int val = temp->val;
                if(evenLevel)
                {
                    if(val % 2 == 0)
                        return false;
                    if(val <= evenLast)
                        return false;
                    evenLast = val;
                }
                else
                {
                    if(val % 2 != 0)
                        return false;
                    if(val >= oddLast)
                        return false;
                    oddLast = val;
                }

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }

            evenLevel = !evenLevel;
        }

        return true;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
