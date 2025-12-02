
#include<iostream>
using namespace std;
class Node
{
    int val;
    Node* next;
    Node():val{},next{nullptr}{}
    Node(int n,Node* temp=nullptr):val{n},next{temp}{}
    friend class MinStack;
};
class MinStack {
public:
long long min;
    Node* head;
    MinStack() :head{nullptr},min{INT_MAX}
    {
    }
    
    void push(int val) 
    {
        Node *nNode=new Node(val,head);
        if(val<=min)
        {
            min=val;
        }    
        head=nNode;

    }
    
    void pop() 
    {
        if(head)
        {
            Node* temp=head;
            head=head->next;
            // delete temp;
            temp=head;
            if(temp)
            {
                min=temp->val;
            }
            while(temp)
            {
                if(temp->val<=min)
                {
                    min=temp->val;
                }
                temp=temp->next;
            }

        }
        else
        {
            throw "Emtyp Stack";
        }
        
    }
    
    int top() {
        if(head)
        {
            return head->val;
        }
        throw "Empty Stack";
    }
    
    int getMin() {
        if(!head)
        {
            throw  "Empty Stack";
        }
        return min;
    }
};

//["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top",
//"getMin","push","top","getMin","pop","getMin"]
//[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]
//[null,null,null,null,
//2147483647,null,2147483646,
//null,2147483646,null,null,2147483647,
//2147483647,null,-2147483648,-2147483648,null,2147483647]
int main()
{
    MinStack obj;
    obj.push(2147483646);
    obj.push(2147483646);
    obj.push(2147483647);
    cout<<"top:\t"<<obj.top()<<endl;
    obj.pop();
    cout<<"Min :\t"<<obj.getMin()<<endl;
    obj.pop();
    cout<<"Min :\t"<<obj.getMin()<<endl;
    obj.pop();
    obj.push(2147483647);
    cout<<"top:\t"<<obj.top()<<endl;
    cout<<"Min :\t"<<obj.getMin()<<endl;
    obj.push(-2147483648);
    cout<<"top:\t"<<obj.top()<<endl;
    cout<<"Min :\t"<<obj.getMin()<<endl;
    obj.pop();
    cout<<"Min :\t"<<obj.getMin()<<endl;


    return 0;
}
