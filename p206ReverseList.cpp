#include"p1800.cpp"
#include<stack>
class Node
{
    public:
    int val;
    Node* next;
    
    Node(int m_val,Node* ptr=nullptr):val{m_val},next{ptr}{}
    Node* reverseList(Node*);
};
Node* reverseList(Node* head) 
    {
        stack<int> arr;
        Node* temp=head;
        while(temp)
        {
            arr.push(temp->val);
            temp=temp->next;
        }
       Node* curr{head};
        while(curr)
        {
            curr->val=arr.top();
            arr.pop();
            curr=curr->next;
        }
        return head;
    }