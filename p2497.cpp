#include<iostream>
using namespace std;
// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* removeNodes(ListNode* head) 
    {
        if(head and head->next)
        {
            
            ListNode* pre{nullptr};
            ListNode* curr{head};
            ListNode* cnext{curr->next};
            while(cnext and curr) 
            {
                if(cnext->val>curr->val)
                {
                    if(curr==head)
                    {
                        head=head->next;
                        delete curr;
                        curr=head;
                    }
                    else
                    {
                        if(pre)
                        {
                            curr=curr->next;
                            delete pre->next;
                            pre->next=curr;   
                        }
                    }
                }
                else
                {
                    cnext=cnext->next;
                    if(cnext==nullptr)
                    {
                        pre=curr;
                        curr=curr->next;
                        cnext=curr->next;
                    }
                }
            }
        }
        return head;
        
    }
};
int main()
{
    ListNode arr;
    return 0;
}