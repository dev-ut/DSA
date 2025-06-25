class Solution {
public:
    ListNode* reverse(ListNode* head) 
    {  
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;
        while (curr != NULL) 
        {
            Next = curr->next; 
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;  // Correction: Changed the return statement to return the head of the reversed list.
    }

    bool isPalindrome(ListNode* head) 
    {
        if (!head || !head->next)
            return true;

          ListNode* slow=head;
          ListNode* fast =head;
          // finfing left middle
          while(fast->next!=NULL && fast->next->next!=NULL)
          {
                slow= slow->next;
                fast=fast->next->next;
          }  
          // now slow is at left middle whan se eak jyada ko reverse krna hai
          // to ek pointer bna lo
          ListNode* newhead=reverse(slow->next);
          // make 2 ponter
          ListNode*a=head;
          ListNode*b=newhead;
          // check

          while(b!=NULL)
          {
              if(a->val!=b->val) return false;
              else 
              {
                  a=a->next;
                  b=b->next;
          }
          }
       return true;
    }
};
