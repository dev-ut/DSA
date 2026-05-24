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
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode* oddhead= new ListNode(0);
        ListNode* evenhead=new ListNode(0);
        ListNode* eventail=evenhead;
        ListNode* oddtail=oddhead;
        int size=0;
        ListNode* temp=head;

        while(temp!=NULL)
        {
            size++;
            if(size%2!=0) // odd index
            {
             oddtail->next=temp;
             oddtail=oddtail->next;
            }
            else
            {
             eventail->next=temp;
             eventail=eventail->next;
            }
            temp=temp->next;
        }
        // connect 
        eventail->next=nullptr;
        oddtail->next=evenhead->next;
        

        return oddhead->next;
    }
};