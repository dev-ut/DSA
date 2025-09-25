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
       // sabse pehle cycle pkdet hai ki  hai ki nhi 
       ListNode* slow=head;
       ListNode*fast=head;
       bool flag=false;
       while(fast!=NULL && fast->next!=nullptr)
       {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
         flag=true;
         break;
        } 
       }

       if(flag==false) return NULL;
       else
       {
        fast=head;
        while(fast!=slow)
        {
          slow=slow->next;  // dono ko eak hi baar bdahya hai 
          fast=fast->next;  // ye ab jo bhi starting point hoga us position pr meet kr jyenge
        }
         return fast;
       }
    }
};