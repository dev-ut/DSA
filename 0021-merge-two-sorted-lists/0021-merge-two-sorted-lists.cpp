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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
      ListNode * tempa=list1;
      ListNode * tempb=list2;

      ListNode* c=new ListNode(-1);
      ListNode *tempc= c;
      while(tempa!=NULL && tempb!=NULL)
      {
        if(tempa->val<=tempb->val)
        {
            tempc->next=tempa;
            tempa=tempa->next;
        }
        else
        {
            tempc->next=tempb;
            tempb=tempb->next;
        }

        tempc=tempc->next;
      }

      while(tempa!=NULL)
      {
        tempc->next=tempa;
        tempa=tempa->next;
        tempc=tempc->next;
       }
       while(tempb!=NULL)
      {
        tempc->next=tempb;
        tempb=tempb->next;
        tempc=tempc->next;
       }
      tempc=c;
      return tempc->next;
        
    }
};