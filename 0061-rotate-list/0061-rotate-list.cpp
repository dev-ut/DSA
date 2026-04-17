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
    ListNode* rotateRight(ListNode* head, int k) 
    {
      if(head==NULL || head->next==NULL || k==0) return head;  
      ListNode* temp=head;
      ListNode* tail=head;    
      int size=0;
      while(temp!=NULL)
      {
        if(temp->next!=NULL) tail=tail->next;
        temp=temp->next;
        size++;
        
      }
      
      temp=head;
      k=k%size;
      tail->next=head; // amke it cyclic
      int it=size-k;
      while(it>1)
      {
        temp=temp->next;
        it--;
      }
      ListNode * nh=temp->next;
      temp->next=nullptr;

      return nh;
    }
};