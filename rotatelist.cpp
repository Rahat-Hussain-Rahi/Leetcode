#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head)
        {
            int num{};
            ListNode *pre{head};
            while (pre)
            {
                ++num;
                pre = pre->next;
            }
            int i{1};
            k = k % num;
            while (i <= k)
            {
                ListNode *temp{head};
                int curr{}, Next{};
                curr = temp->val;
                temp = temp->next;
                while (temp)
                {
                    Next = temp->val;
                    temp->val = curr;
                    curr = Next;
                    temp = temp->next;
                }
                head->val = curr;
                ++i;
            }
        }
        return head;
    }
};