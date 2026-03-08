
#include<iostream>
#include<vector>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        vector<int> vec1;
        vector<int> vec2;
        ListNode* curr{l1};
        while(curr)
        {
            vec1.push_back(curr->val);
            curr=curr->next;
        }
        ListNode* curr1{l2};
        while(curr1)
        {
            vec2.push_back(curr1->val);
            curr1=curr1->next;
        }
        vector<int> result;
        int carry=0;
        int sum=0;
        int size1=vec1.size();
        int size2=vec2.size();
        int i{size1-1},j{size2-1};
        for(;j>=0&&i>=0;--i,--j)
        {
            sum=vec1[i]+vec2[j]+carry;
            carry=0;
            if(sum>=10)
            {
                carry=1;
                sum-=10;
            }
            result.push_back(sum);
        }
        if(i==0&&j==0)
        {
            if(carry==1)
            {
                result.push_back(carry);
            }
            carry=0;
        }
        else
        {
            while(i>=0)
            {
                sum=vec1[i]+carry;
                carry=0;
                if(sum>=10)
                {
                    carry=1;
                    sum-=10;
                }
                 result.push_back(sum);
                --i;
            }
            while(j>=0)
            {
                sum=vec2[j]+carry;
                carry=0;
                if(sum>=10)
                {
                    carry=1;
                    sum-=10;
                }
                result.push_back(sum);
                --j;
            }
            if(carry==1)
            {
                result.push_back(carry);
            }
        }
        ListNode* add=new ListNode();
        ListNode* head=add;
        int size3=result.size();
        --size3;
        while(size3>=0)
        {
            add->val=result[size3];
            
            --size3;
            if(size3>=0)
            {
                add->next=new ListNode();
                add=add->next;
            }
        }
        return head;
    }
};