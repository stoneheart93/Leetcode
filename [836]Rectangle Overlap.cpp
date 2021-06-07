//An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1
//, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinat
//e of its top-right corner. Its top and bottom edges are parallel to the X-axis, 
//and its left and right edges are parallel to the Y-axis. 
//
// Two rectangles overlap if the area of their intersection is positive. To be c
//lear, two rectangles that only touch at the corner or edges do not overlap. 
//
// Given two axis-aligned rectangles rec1 and rec2, return true if they overlap,
// otherwise return false. 
//
// 
// Example 1: 
// Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
//Output: true
// Example 2: 
// Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
//Output: false
// Example 3: 
// Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
//Output: false
// 
// 
// Constraints: 
//
// 
// rect1.length == 4 
// rect2.length == 4 
// -109 <= rec1[i], rec2[i] <= 109 
// rec1[0] <= rec1[2] and rec1[1] <= rec1[3] 
// rec2[0] <= rec2[2] and rec2[1] <= rec2[3] 
// 
// Related Topics Math 
// 👍 1060 👎 321


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
    {
        int rec1_bot_x = rec1[0], rec1_bot_y = rec1[1], rec1_top_x = rec1[2], rec1_top_y = rec1[3];
        int rec2_bot_x = rec2[0], rec2_bot_y = rec2[1], rec2_top_x = rec2[2], rec2_top_y = rec2[3];

        if(rec1_bot_x == rec1_top_x || rec1_bot_y == rec1_top_y || rec2_bot_x == rec2_top_x || rec2_bot_y == rec2_top_y)
            return false;
        if(rec2_bot_x >= rec1_top_x || rec1_bot_x >= rec2_top_x)
            return false;
        if(rec2_bot_y >= rec1_top_y || rec1_bot_y >= rec2_top_y)
            return false;
        return true;
    }
};

//Time Complexity: O(1)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
