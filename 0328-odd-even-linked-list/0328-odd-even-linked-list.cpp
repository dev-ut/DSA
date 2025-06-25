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
    if (head == NULL || head->next == NULL) return head;  // jb two se jyafd ho tbhi list bnao 

    // Dummy nodes for odd and even
    ListNode* oddhead = new ListNode(-1);
    ListNode* evenhead = new ListNode(-1);
    
    // Tail pointers for both lists
    ListNode* oddtail = oddhead;
    ListNode* eventail = evenhead;

    ListNode* temp = head;
    int index = 1; // 1-based index (odd position starts from 1)

    while (temp != nullptr)
    {
        if (index % 2 != 0) // odd position node
        {
            oddtail->next = temp;
            oddtail = oddtail->next;
        }
        else // even position node
        {
            eventail->next = temp;
            eventail = eventail->next;
        }
        temp = temp->next;
        index++;
    }

    // Important: terminate even list properly
    eventail->next = nullptr;

    // Join odd list with even list
    oddtail->next = evenhead->next;

    // Final result starts after dummy node
    return oddhead->next;
}
};