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
       // agr do node se km ho aur k 0 ho to
        
       if(head==NULL || head->next==NULL||k==0) return head;
       ListNode*temp=head;
       int size=1;
       while(temp!=NULL && temp->next!=NULL)
       {
          size++;
          temp=temp->next;
       }
       k=k%size;
       if(k==0) return head;
      // now wee have to make it cicrcular taki it shoyld joing head
       temp->next=head;
     // nnow we iwll amke sure from whicj index are we going to roate
       int indx=size-k;
       temp=head;
       for(int i=1;i<indx;i++)
       {
        temp=temp->next;   // temp is positioned below it has to be rotated
       }
      // set new haed 
      ListNode* newhead=temp->next;
      temp->next=nullptr;
      return newhead;

    }
};