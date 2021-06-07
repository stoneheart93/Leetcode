//Given two binary search trees root1 and root2. 
//
// Return a list containing all the integers from both trees sorted in ascending
// order. 
//
// 
// Example 1: 
//
// 
//Input: root1 = [2,1,4], root2 = [1,0,3]
//Output: [0,1,1,2,3,4]
// 
//
// Example 2: 
//
// 
//Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
//Output: [-10,0,0,1,2,5,7,10]
// 
//
// Example 3: 
//
// 
//Input: root1 = [], root2 = [5,1,7,0,2]
//Output: [0,1,2,5,7]
// 
//
// Example 4: 
//
// 
//Input: root1 = [0,-10,10], root2 = []
//Output: [-10,0,10]
// 
//
// Example 5: 
//
// 
//Input: root1 = [1,null,8], root2 = [8,1]
//Output: [1,1,8,8]
// 
//
// 
// Constraints: 
//
// 
// Each tree has at most 5000 nodes. 
// Each node's value is between [-10^5, 10^5]. 
// 
// Related Topics Sort Tree 
// 👍 1002 👎 36


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
    void storeInorder(struct TreeNode* root, vector<int>& a)
    {
        if(root == NULL)
            return;

        storeInorder(root->left, a);
        a.push_back(root->val);
        storeInorder(root->right, a);
    }

    void mergeSortedArrays(vector<int>& a, vector<int>& b, vector<int>& c)
    {
        int i = 0, j = 0, k = 0;
        while(i < a.size() && j < b.size())
        {
            if(a[i] <= b[j])
                c.push_back(a[i++]);
            else
                c.push_back(b[j++]);
        }

        while(i < a.size())
            c.push_back(a[i++]);
        while(j < b.size())
            c.push_back(b[j++]);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> a;
        storeInorder(root1, a);

        vector<int> b;
        storeInorder(root2, b);

        vector<int> c;
        mergeSortedArrays(a, b, c);
        return c;
    }
};

//Time Complexity: O(m + n)
//Space Complexity: O(m + n)

//leetcode submit region end(Prohibit modification and deletion)
