/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
      ListNode* slow=head;
      ListNode* fast=head;
      bool flag=false;
      if(head==NULL || head->next==NULL) return NULL;

      while(fast!=NULL && fast->next!=NULL)
      {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
         flag=true;
         break;
        } 
        
      }
      if(flag==false) return nullptr; 
      else
      {
        ListNode* temp=head;

        while(temp!=slow)
        {
            slow=slow->next;
            temp=temp->next;
        }
        return temp; 
      }
    }
};