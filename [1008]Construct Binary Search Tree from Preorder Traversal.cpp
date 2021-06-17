//Given an array of integers preorder, which represents the preorder traversal o
//f a BST (i.e., binary search tree), construct the tree and return its root. 
//
// It is guaranteed that there is always possible to find a binary search tree w
//ith the given requirements for the given test cases. 
//
// A binary search tree is a binary tree where for every node, any descendant of
// Node.left has a value strictly less than Node.val, and any descendant of Node.r
//ight has a value strictly greater than Node.val. 
//
// A preorder traversal of a binary tree displays the value of the node first, t
//hen traverses Node.left, then traverses Node.right. 
//
// 
// Example 1: 
//
// 
//Input: preorder = [8,5,1,7,10,12]
//Output: [8,5,10,1,7,null,12]
// 
//
// Example 2: 
//
// 
//Input: preorder = [1,3]
//Output: [1,null,3]
// 
//
// 
// Constraints: 
//
// 
// 1 <= preorder.length <= 100 
// 1 <= preorder[i] <= 108 
// All the values of preorder are unique. 
// 
// Related Topics Tree 
// 👍 2011 👎 49


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

    struct TreeNode* bstFromPreorderUtil(vector<int>& preorder, int& index, int min, int max)
    {
        if(index == preorder.size())
            return NULL;

        struct TreeNode* root = NULL;
        int key = preorder[index];

        if(key >= min && key <= max)
        {
            root = newNode(key);
            index++;
            root->left = bstFromPreorderUtil(preorder, index, min, key - 1);
            root->right = bstFromPreorderUtil(preorder, index, key + 1, max);
        }

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        int index = 0;
        return bstFromPreorderUtil(preorder, index, INT_MIN, INT_MAX);
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
