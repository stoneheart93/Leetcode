//Given an integer n, return all the structurally unique BST's (binary search tr
//ees), which has exactly n nodes of unique values from 1 to n. Return the answer 
//in any order. 
//
// 
// Example 1: 
//
// 
//Input: n = 3
//Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]
//]
// 
//
// Example 2: 
//
// 
//Input: n = 1
//Output: [[1]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 8 
// 
// Related Topics Dynamic Programming Tree 
// 👍 3142 👎 213


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

    struct TreeNode* newNode(int data)
    {
        struct TreeNode* temp = new struct TreeNode;
        temp->val = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    vector<struct TreeNode*> generateTreesUtil(int start, int end)
    {
        vector<struct TreeNode*> result;

        if(start > end)
        {
            result.push_back(NULL);
            return result;
        }


        for(int i = start; i <= end; i++)
        {
            vector<struct TreeNode*> left = generateTreesUtil(start, i - 1);
            vector<struct TreeNode*> right = generateTreesUtil(i + 1, end);

            for(int j = 0; j < left.size(); j++)
            {
                for(int k = 0; k < right.size(); k++)
                {
                    struct TreeNode* root = newNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    result.push_back(root);
                }
            }
        }

        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n)
    {
        return generateTreesUtil(1, n);
    }
};

//Time Complexity: O(catalan(n))
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
