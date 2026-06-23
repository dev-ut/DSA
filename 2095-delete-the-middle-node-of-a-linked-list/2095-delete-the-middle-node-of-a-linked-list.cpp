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
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }

        if(size<=1) return nullptr;
        // will gonna to take out the middele 
        int middle=size/2;
        temp=head;
        for(int i=0;i<middle-1;i++)
        {
            temp=temp->next;
        }
        // delte the middle node 
        ListNode* delnode=temp->next;
        // join the two nodes 
        temp->next=delnode->next;

        delete delnode;

        return head;

    }
};