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
    ListNode* reverseList(ListNode* head)
    {
        ListNode *prev= NULL;
        ListNode *curr=head;
        ListNode *next=head;

        while(curr!=NULL)
        {
            next=curr->next; // next age chlagya
            curr->next=prev;
            prev=curr;  // prev ko age kiya
            curr=next;  // next ko age kiya
        }
        return prev;
    }
};