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
ListNode * rev(ListNode * head)
{
    ListNode* prev=nullptr;
    ListNode* curr=head;
    ListNode* next=head;

    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) 
    {
       if(head==NULL || head->next==NULL) return true;
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast!=NULL && fast->next!=NULL) 
       {
      slow=slow->next;
      fast=fast->next->next;
       }
      
       // now halfves 12321 why second half 
       ListNode* secondhalf=rev(slow);
       ListNode* firsthalf=head;
       // checking the values

       while(secondhalf!=NULL)
       {
        if(firsthalf->val!=secondhalf->val) return false;

        firsthalf=firsthalf->next;
        secondhalf=secondhalf->next;
       }
       return true;

    }
};