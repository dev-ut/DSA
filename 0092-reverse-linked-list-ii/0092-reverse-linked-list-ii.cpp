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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
         if (head == nullptr || left == right) return head;

    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* prev = dummy;

    // Move prev to the node before the left position
    for (int i = 1; i < left; i++) 
    {
        prev = prev->next;
    }

    ListNode* current = prev->next;
    ListNode* nextNode = nullptr;
    ListNode* beforeLeft = prev;

    for (int i = left; i <= right; i++) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // Connect the reversed part back to the original list
    beforeLeft->next->next = current;
    beforeLeft->next = prev;

    return dummy->next;
    }
};