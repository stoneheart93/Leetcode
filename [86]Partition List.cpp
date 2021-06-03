//Given the head of a linked list and a value x, partition it such that all node
//s less than x come before nodes greater than or equal to x. 
//
// You should preserve the original relative order of the nodes in each of the t
//wo partitions. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,4,3,2,5,2], x = 3
//Output: [1,2,2,4,3,5]
// 
//
// Example 2: 
//
// 
//Input: head = [2,1], x = 2
//Output: [1,2]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [0, 200]. 
// -100 <= Node.val <= 100 
// -200 <= x <= 200 
// 
// Related Topics Linked List Two Pointers 
// 👍 2345 👎 415


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        struct ListNode* firstStart = NULL;
        struct ListNode* firstEnd = NULL;
        struct ListNode* secondStart = NULL;
        struct ListNode* secondEnd = NULL;

        struct ListNode* rider = head;
        while(rider != NULL)
        {
            if(rider->val < x)
            {
                if(firstStart == NULL)
                {
                    firstStart = rider;
                    firstEnd = rider;
                }
                else
                {
                    firstEnd->next = rider;
                    firstEnd = rider;
                }
            }
            else
            {
                if(secondStart == NULL)
                {
                    secondStart = rider;
                    secondEnd = rider;
                }
                else
                {
                    secondEnd->next = rider;
                    secondEnd = secondEnd->next;
                }
            }

            rider = rider->next;
        }

        if(firstStart == NULL || secondStart == NULL)
            return head;

        head = firstStart;
        firstEnd->next = secondStart;
        secondEnd->next = NULL;

        return head;
    }
};

//Time Complexity: O(len)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
