/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) 
    {
        if(head)
        {
            Node* temp{head};
            Node* Next{nullptr};
            while(temp)
            {
                if(temp->child)
                {
                    Next=temp->next;
                    temp->next=temp->child;
                    temp->child->prev=temp;
                    temp->child=nullptr;
                    Node* child1{temp->next};
                    while(child1->next)
                    {
                        child1=child1->next;
                    }
                    child1->next=Next;
                    if(Next)
                    {
                        Next->prev=child1;
                       // Next->next=nullptr;
                    }
                   
                }
                temp=temp->next;
            }
        }
        return head;
        
    }
};