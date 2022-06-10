/*
    link: https://leetcode.com/problems/linked-list-cycle-ii/
*/

/*
    comment:
    for judging a cycle, a typical method is Floyd cycle detection algorithm
    let there be two pointers: one fast and one slow where fast moves twice as fast as slow
    if fast hits null then therer's no loop
    else they must meet somewhere
    when they meet move one of the pointer to the start and both pointers move once at a time
    when they meet again, the position is the start of the loop
*/

/*
    status:
    Runtime: 43.12%
    Memory Usage: 74.30%
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        do {
            if (!fast || !fast->next || !fast->next->next) {
                return NULL;
            } else {
                fast = fast->next->next;
                slow = slow->next;
            }
        } while (fast != slow);
        
        fast = head;
        
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;
        
    }
};