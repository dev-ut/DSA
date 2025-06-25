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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
       int size=0; 
       ListNode* temp=head;

       while(temp!=nullptr)
       {
        size++;
        temp=temp->next;
       }

       int tempiteration =size-n;
       // Edge case: remove head
      if (tempiteration == 0)  // ye tb hoga jb n==sizze ho jyega ie last ka ist node ho jyega isiliye yeh return kr rhe  
        return head->next;

       temp=head;

       for(int i=1;i<tempiteration;i++)
       {
         temp=temp->next;
       }
       
       // just remove
       temp->next=temp->next->next;
       return head;

    }
};