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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
      ListNode* t1=l1;
      ListNode* t2=l2;
      ListNode* c=new ListNode(0);
      ListNode* tempc=c;
      int carry=0;
      while(t1!=NULL || t2!=NULL)
      {
        int sum=0+carry;

        if(t1!=NULL)
        {
            sum+=t1->val;
            t1=t1->next;
        }
        if(t2!=NULL)
        {
            sum+=t2->val;
            t2=t2->next;
        }

        carry=sum/10;
        sum=sum%10;
        tempc->next= new ListNode (sum);
        tempc=tempc->next;

      } 

      if(carry>0)
      {
        tempc->next= new ListNode (carry);
      }
      tempc=c;
      return tempc->next;   
    }
};