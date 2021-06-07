//You are given the root of a binary tree where each node has a value 0 or 1. Ea
//ch root-to-leaf path represents a binary number starting with the most significa
//nt bit. For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could repre
//sent 01101 in binary, which is 13. 
//
// For all leaves in the tree, consider the numbers represented by the path from
// the root to that leaf. 
//
// Return the sum of these numbers. The answer is guaranteed to fit in a 32-bits
// integer. 
//
// 
// Example 1: 
//
// 
//Input: root = [1,0,1,0,1,0,1]
//Output: 22
//Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
// 
//
// Example 2: 
//
// 
//Input: root = [0]
//Output: 0
// 
//
// Example 3: 
//
// 
//Input: root = [1]
//Output: 1
// 
//
// Example 4: 
//
// 
//Input: root = [1,1]
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 1000]. 
// Node.val is 0 or 1. 
// 
// Related Topics Tree 
// 👍 1269 👎 96


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
    int convertBinaryToDecimal(string& binary)
    {
        int decimal = 0;
        int base = 1;

        for(int i = binary.size() - 1; i >= 0; i--)
        {
            if(binary[i] == '1')
                decimal += base;
            base *= 2;
        }

        return decimal;
    }

    void sumRootToLeafUtil(struct TreeNode* root, string binary, int& sum)
    {
        if(root == NULL)
            return;

        binary += to_string(root->val);

        if(root->left == NULL && root->right == NULL)
        {
            sum += convertBinaryToDecimal(binary);
            return;
        }

        sumRootToLeafUtil(root->left, binary, sum);
        sumRootToLeafUtil(root->right, binary, sum);
    }
public:
    int sumRootToLeaf(TreeNode* root)
    {
        int sum = 0;
        sumRootToLeafUtil(root, "", sum);
        return sum;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
