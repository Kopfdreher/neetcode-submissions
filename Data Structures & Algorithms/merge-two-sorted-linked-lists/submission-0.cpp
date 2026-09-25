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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* current;
        ListNode* merged;
        if (list1->val < list2->val) {
            merged = list1;
            list1 = list1->next;
        } else {
            merged = list2;
            list2 = list2->next;
        }

        current = merged;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                current->next = list1;
                current = current->next;
                list1 = list1->next;
            } else {
                current->next = list2;
                current = current->next;
                list2 = list2->next;
            }
        }

        if (list1) current->next = list1;
        if (list2) current->next = list2;
        return merged;
    }
};