/*
    link: https://leetcode.com/problems/linked-list-cycle/
*/

/*
    comment:
    a simple version of the cycle judge algorithm
*/

/*
    status:
    Runtime: 81.46%
    Memory Usage: 57.30%
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    ListNode *next;
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast) {
            fast = fast->next;
            if (!fast) {
                return false;
            }
            fast = fast->next;
            if (!fast) {
                return false;
            }
            if (fast == slow) {
                return true;
            }
            slow = slow->next;
            
        }
        return false;
    }
};