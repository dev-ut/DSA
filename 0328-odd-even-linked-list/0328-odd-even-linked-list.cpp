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
ListNode* oddEvenList(ListNode* head) 
{
    if (head == NULL || head->next == NULL) return head;

    // Directly use original nodes
    ListNode* odd = head;            // 1st node
    ListNode* even = head->next;     // 2nd node
    ListNode* evenHead = even;       // for final joining

    while (even && even->next)
    {
        odd->next = even->next;      // odd ko next odd se jodo
        odd = odd->next;             // odd aage badhao

        even->next = odd->next;      // even ko next even se jodo
        even = even->next;           // even aage badhao
    }

    // end mein odd ka next evenHead se jod do
    odd->next = evenHead;

    return head;
}

};