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
       // edge case handle ki what if list null ho and left or right baraabbr ho so return same llist
       if(head==NULL || left ==right) return head;
       // now we will make dummy node so that probel na aye 
       ListNode* dummy = new ListNode(-1);
       dummy->next=head;

       // now to revrse 
       ListNode* prev=dummy;
       // now we got to place prev to the left 
       for(int i=1;i<left;i++)
       {
        prev=prev->next;
       }
       ListNode* curr=prev->next;
       ListNode* next=NULL;
       ListNode* beforeLeft=prev;

       for(int i=left;i<=right;i++)
       {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
       }
       // joining
       beforeLeft->next->next=curr;
       beforeLeft->next=prev;

       return dummy->next;
    }
};