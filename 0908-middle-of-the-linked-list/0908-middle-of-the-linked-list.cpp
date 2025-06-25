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
    ListNode* middleNode(ListNode* head) {

        //  //find length . lenth niklnai hai to we got toi traverse
        //  int size=0;
        //  ListNode* temp=head;
        //  while(temp!=NULL)
        //  {
        //      temp=temp->next;
        //      size++;
        //  }
        //    int midIndx=size/2; // in bothb case even and odd it will give coreect vale

        //    //now we have to given output 
        //    //very imp ..u can make another node for orr can make temp to come initally at head lets see both
        //    temp=head;
        //    for(int i=0;i<midIndx;i++)
        //    {
        //        temp=temp->next;
        //    }
        //    return temp;

         //2nd methodd using slow and fast pointer techniques
         ListNode *slow=head;
         ListNode *fast=head;
         while(fast!=NULL && fast->next!=NULL)
         {
             slow=slow->next;
             fast=fast->next->next;
         }
         return slow;
    }
};