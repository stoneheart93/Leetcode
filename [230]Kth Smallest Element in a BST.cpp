//Given the root of a binary search tree, and an integer k, return the kth (1-in
//dexed) smallest element in the tree. 
//
// 
// Example 1: 
//
// 
//Input: root = [3,1,4,null,2], k = 1
//Output: 1
// 
//
// Example 2: 
//
// 
//Input: root = [5,3,6,2,4,null,null,1], k = 3
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is n. 
// 1 <= k <= n <= 104 
// 0 <= Node.val <= 104 
// 
//
// 
//Follow up: If the BST is modified often (i.e., we can do insert and delete ope
//rations) and you need to find the kth smallest frequently, how would you optimiz
//e? Related Topics Binary Search Tree 
// 👍 4008 👎 89


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
    int kthSmallest(TreeNode* root, int k)
    {
        struct TreeNode* current = root;
        int count = 0;
        int ksmall = -1;

        while(current != NULL)
        {
            if(current->left == NULL)
            {
                count++;
                if(count == k)
                    ksmall = current->val;

                current = current->right;
            }
            else
            {
                struct TreeNode* pre = current->left;
                while(pre->right != NULL && pre->right != current)
                    pre = pre->right;

                if(pre->right == NULL)
                {
                    pre->right = current;
                    current = current->left;
                }
                else
                {
                    pre->right = NULL;

                    count++;
                    if(count == k)
                        ksmall = current->val;

                    current = current->right;
                }
            }
        }

        return ksmall;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)


//leetcode submit region end(Prohibit modification and deletion)
