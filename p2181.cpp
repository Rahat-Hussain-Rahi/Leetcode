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
    ListNode* mergeNodes(ListNode* head) 
    {
        if(head)
        {
            ListNode* curr{head};
            head=head->next;
            //delete curr;
            ListNode* temp{head};
            while((temp)&&(temp->next))
            {
                if((temp->val!=0)&&(temp->next->val!=0))
                {
                    temp->val+=(temp->next->val);
                    ListNode* curr=temp->next;
                    temp->next=curr->next;
                    delete curr;
                }
                else if(temp->next->val==0)
                {
                    ListNode* ptr=temp->next;
                    temp->next=ptr->next;
                    delete ptr;
                    temp=temp->next;
                }
            }
        }
        return head;
        
    }
};