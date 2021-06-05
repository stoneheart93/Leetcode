//Given the root of a binary tree, calculate the vertical order traversal of the
// binary tree. 
//
// For each node at position (row, col), its left and right children will be at 
//positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of th
//e tree is at (0, 0). 
//
// The vertical order traversal of a binary tree is a list of top-to-bottom orde
//rings for each column index starting from the leftmost column and ending on the 
//rightmost column. There may be multiple nodes in the same row and same column. I
//n such a case, sort these nodes by their values. 
//
// Return the vertical order traversal of the binary tree. 
//
// 
// Example 1: 
//
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: [[9],[3,15],[20],[7]]
//Explanation:
//Column -1: Only node 9 is in this column.
//Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
//Column 1: Only node 20 is in this column.
//Column 2: Only node 7 is in this column. 
//
// Example 2: 
//
// 
//Input: root = [1,2,3,4,5,6,7]
//Output: [[4],[2],[1,5,6],[3],[7]]
//Explanation:
//Column -2: Only node 4 is in this column.
//Column -1: Only node 2 is in this column.
//Column 0: Nodes 1, 5, and 6 are in this column.
//          1 is at the top, so it comes first.
//          5 and 6 are at the same position (2, 0), so we order them by their v
//alue, 5 before 6.
//Column 1: Only node 3 is in this column.
//Column 2: Only node 7 is in this column.
// 
//
// Example 3: 
//
// 
//Input: root = [1,2,3,4,6,5,7]
//Output: [[4],[2],[1,5,6],[3],[7]]
//Explanation:
//This case is the exact same as example 2, but with nodes 5 and 6 swapped.
//Note that the solution remains the same since 5 and 6 are in the same location
// and should be ordered by their values.
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 1000]. 
// 0 <= Node.val <= 1000 
// 
// Related Topics Hash Table Tree Depth-first Search Breadth-first Search 
// 👍 1587 👎 2513


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
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        vector<vector<int>> result;
        if(root == NULL)
            return result;

        map<int, vector<int>> hash;
        int hd = 0;
        queue<pair<struct TreeNode*, int>> q;
        q.push({root, hd});

        while(1)
        {
            int n = q.size();

            if(n == 0)
                break;

            map<int, vector<int>> hash_temp;
            for(int i = 1; i <= n; i++)
            {
                pair<struct TreeNode*, int> temp_pair = q.front();
                q.pop();

                struct TreeNode* temp = temp_pair.first;
                hd = temp_pair.second;

                hash_temp[hd].push_back(temp->val);

                if(temp->left)
                    q.push({temp->left, hd - 1});
                if(temp->right)
                    q.push({temp->right, hd + 1});
            }
            for(auto it = hash_temp.begin(); it != hash_temp.end(); it++)
            {
                sort(it->second.begin(), it->second.end());
                hash[it->first].insert(hash[it->first].end(), it->second.begin(), it->second.end());
            }
        }

        for(auto it = hash.begin(); it != hash.end(); it++)
        {
            result.push_back(it->second);
        }

        return result;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
