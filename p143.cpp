
// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void reorderList(ListNode* head) 
    {
        if(head and head->next)
        {
            ListNode* temp{head};
            ListNode* last{head->next};
            ListNode* pre{head};
            while(temp and temp!=last and temp->next)
            {
                pre=last;
                while((last->next)&&(last!=temp))
                {
                    pre=last;
                    last=last->next;
                }
                last->next=temp->next;
                temp->next=last;
                temp=last->next;
                pre->next=nullptr;
                last=temp->next;
            }
        }
        
    }
};