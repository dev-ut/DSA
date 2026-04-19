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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }

        int sn=size-k;
        ListNode* it=head;

        for(int i=1;i<=sn;i++)
        {
            it=it->next;
        }
        temp=head;
        for(int i=1;i<k;i++)
        {
            temp=temp->next;

        }
       swap(temp->val,it->val);
       return head;

    }
};