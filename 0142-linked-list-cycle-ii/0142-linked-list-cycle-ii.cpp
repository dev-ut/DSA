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
      ListNode *s=head;
      ListNode* f=head;
      int flag=0;

      if(f==NULL || f->next==NULL) return NULL;

      while(f!=NULL && f->next!=NULL)
      {
        s=s->next;
        f=f->next->next;
        if(s==f) 
        {
            flag=1;
            break;
        }
      }
      if(flag==0) return nullptr;
      ListNode* temp=head;

      while(temp!=s)
      {
        temp=temp->next;
        s=s->next;
        
      }

     return s;

    }
};