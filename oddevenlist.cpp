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
    ListNode* oddEvenList(ListNode* head) 
    {
          ListNode* oddpre{nullptr};
          ListNode* evenpre{nullptr};
          ListNode* curr{head};
          int count=1;
        while(curr)
        {
            if(count%2==1)
            {
                oddpre=curr;
                curr=curr->next;
                count=0;
            }
            else{
                evenpre=curr;
                curr=curr->next;
                oddpre->next=curr;
                evenpre->next=curr->next;
                curr->next=evenpre;
                oddpre=curr;
                evenpre=evenpre->next;
                count=1;
            }
        } 
           
    }
};
int main()
{
    Solution sub;
}