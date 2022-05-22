/*
    link: https://leetcode.com/problems/middle-of-the-linked-list/
*/

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

struct ListNode;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        while (ptr2->next) {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
            if (!ptr2) {
                return ptr1;
            }
            ptr2 = ptr2->next;
            if (!ptr2) {
                return ptr1;
            }
        }
        return ptr1;
    }
};