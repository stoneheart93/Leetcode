//Given a linked list, return the node where the cycle begins. If there is no cy
//cle, return null. 
//
// There is a cycle in a linked list if there is some node in the list that can 
//be reached again by continuously following the next pointer. Internally, pos is 
//used to denote the index of the node that tail's next pointer is connected to. N
//ote that pos is not passed as a parameter. 
//
// Notice that you should not modify the linked list. 
//
// 
// Example 1: 
//
// 
//Input: head = [3,2,0,-4], pos = 1
//Output: tail connects to node index 1
//Explanation: There is a cycle in the linked list, where tail connects to the s
//econd node.
// 
//
// Example 2: 
//
// 
//Input: head = [1,2], pos = 0
//Output: tail connects to node index 0
//Explanation: There is a cycle in the linked list, where tail connects to the f
//irst node.
// 
//
// Example 3: 
//
// 
//Input: head = [1], pos = -1
//Output: no cycle
//Explanation: There is no cycle in the linked list.
// 
//
// 
// Constraints: 
//
// 
// The number of the nodes in the list is in the range [0, 104]. 
// -105 <= Node.val <= 105 
// pos is -1 or a valid index in the linked-list. 
// 
//
// 
// Follow up: Can you solve it using O(1) (i.e. constant) memory? 
// Related Topics Linked List Two Pointers 
// 👍 4293 👎 314


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
            return NULL;

        struct ListNode* slowptr = head;
        struct ListNode* fastptr = head;

        while(slowptr != NULL && fastptr != NULL && fastptr->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;

            if(slowptr == fastptr)
                break;
        }

        if(slowptr == fastptr)
        {
            slowptr = head;
            while(slowptr != fastptr)
            {
                slowptr = slowptr->next;
                fastptr = fastptr->next;
            }

            return slowptr;
        }
        else
            return NULL;
    }
};

/*
Distance travelled by slowptr = 2 * Distance travelled by fastptr
m + kx + n = 2 * (m + ky + n)
m + n = k * (x - 2y)
*/

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
