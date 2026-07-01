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
ListNode* merge(ListNode* a,ListNode* b)
{
    ListNode* c=new ListNode(0);
    ListNode* tempc=c;

    while(a!=NULL && b!=NULL)
    {
        if(a->val<=b->val)
        {
            tempc->next=a;
            a=a->next;
        }
        else
        {
            tempc->next=b;
            b=b->next;
        }
        tempc=tempc->next;
    }

    if(a!=NULL)
    {
        tempc->next=a;
    }
    else tempc->next=b;

    return c->next;
}
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL) return head;   // base case

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* a=head;
        ListNode* b=slow->next;
        slow->next=NULL;

        // devide further 
        a=sortList(a);
        b=sortList(b);

        // merge them 

        return merge(a,b);
    }
};