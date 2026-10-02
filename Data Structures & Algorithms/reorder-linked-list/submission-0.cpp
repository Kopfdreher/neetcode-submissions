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
  void reorderList(ListNode* head) {
    if (!head || !(head->next)) return;
    int len = 0;
    ListNode* tmp = head;
    while (tmp) {
      len++;
      tmp = tmp->next;
    }
    tmp = head;
    for (int i = 0; i < (len - 1) / 2; ++i) tmp = tmp->next;
    ListNode* second = tmp->next;
    tmp->next = NULL;
    tmp = second;

    ListNode* prev = NULL;
    ListNode* next;
    while (tmp) {
      next = tmp->next;
      tmp->next = prev;
      prev = tmp;
      tmp = next;
    }
    ListNode* nextHead;
    for (int i = 0; i < len / 2; ++i) {
      nextHead = head->next;
      head->next = prev;
      prev = prev->next;
      head = head->next;
      head->next = nextHead;
      head = head->next;
    }
  }
};
