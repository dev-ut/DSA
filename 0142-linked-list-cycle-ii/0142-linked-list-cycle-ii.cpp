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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode*fast=head;
        bool flag=false;
        while(fast!=NULL && fast->next!=NULL) //odd and even
        {
           slow=slow->next;
           fast=fast->next->next;
           if(fast==slow) 
           {
               flag=true;     // mllb pkdi gai cycle
               break;
           }
        }

        if(flag==false) return NULL;
        
        else {
            ListNode* temp= head;
            while(temp!=slow)
            {
                slow=slow->next;    //ek ek se bdhao
                temp=temp->next;
            }
             return temp;
        }
       
        }
};