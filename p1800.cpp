#include<iostream>
using namespace std;
class LinkedList;
class Node
{
    int val;
    Node* next;
    public:
    Node(int m_val,Node* ptr=nullptr):val{m_val},next{ptr}{}
    friend class LinkedList;
};
class LinkedList
{
    Node* head;
    Node* leftright(Node*,int,int);
    Node* reverseposition(Node*,int ,int);
    Node* DeleteNthNode(Node* head,int n);
    public:
    LinkedList():head{nullptr}{}
    void insert(int val);
    void DeleteNthEnd(int n)
    {
        head=DeleteNthNode(head,n);
    }
    void print() const
    {
        Node* temp=head;
        while(temp)
        {
            cout<<temp->val<<' ';
            temp=temp->next;
        }
        cout<<endl;
    }

    void LeftRight(int,int);
    Node* reverseList(Node* head) ;
    
};
 void LinkedList::insert(int val)
    {
        Node* New=new Node(val);
        if(head==nullptr)
        {
            head=New;
            return;
        }
        Node* temp=head;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=New;
    }
 Node* LinkedList::DeleteNthNode(Node* head,int n)
    {
        if((head!=nullptr)&&(n>0))
        {
            int count=1;
            Node* temp=head->next;
            while(temp)
            {
                ++count;
                temp=temp->next;
            }
            if(count==n)
            {
                cout<<endl<<count<<endl;
                head=head->next;
                // Node* curr=head->next;
                // delete head;
                // head=curr;
                return head;;
            }
            int val=count-n-1;
            Node* curr{head};
            int i{1};
            while(i<=val)
            {
                curr=curr->next;
                ++i;
            }
            if(count==n)
            {
                curr=head;
                head=head->next;
                delete curr;
            }
            else if(n==1)
            {
                delete curr->next;
                curr->next=nullptr;
            }
            else
            {
                Node*  ptr=curr->next;
                curr->next=ptr->next;
                delete ptr;
            }
        }
        return head;
    }
void LinkedList::LeftRight(int left,int right)
{
    head=reverseposition(head,left,right);
}
Node* LinkedList::leftright(Node* head,int left,int right)
{
    if(head)
    {
        Node* temp=head;
        Node* curr{nullptr};
        while(temp)
        {
            if(temp->val==left)
            {
                curr=temp->next;
                if((curr)&&(curr->next))
                {
                    curr=curr->next;
                    if((curr)&&(curr->val==right))
                    {
                        temp->val=right;
                        curr->val=left;
                        break;
                    }
                }
            }
            temp=temp->next;
        }
        
    }
    return head;
}
Node* LinkedList::reverseposition(Node* head,int left,int right)
{
    if(head)
    {
        Node* temp=head;
        Node* lptr=nullptr;
        Node* rptr=nullptr;
        int count=0;
        while(temp)
        {
            ++count;
            if(count==left)
            {
                lptr=temp;
                temp=temp->next;
                count+=1;
                while(temp)
                {
                    
                    if(count==right)
                    {
                        rptr=temp;
                        int n=rptr->val;
                        rptr->val=lptr->val;
                        lptr->val=n;
                        Node* curr=lptr->next;
                        while((lptr!=rptr))
                        {
                            lptr=lptr->next;
                            while((curr->next!=rptr)&&(lptr!=rptr))
                            {
                                curr=curr->next;
                            }
                            n=lptr->val;
                            lptr->val=curr->val;
                            curr->val=n;
                            rptr=curr;
                            curr=lptr->next;
                        }
                        return head;
                    }
                    ++count;
                    temp=temp->next;
                }
                break;
            }
            temp=temp->next;
        }
    }
    return head;
}
int main()
{
    LinkedList l1;
    int n;
    cin>>n;
    int val;
    for(int i{};i<n;++i)
    {
        cin>>val;
        l1.insert(val);
    }
    l1.print();
    int l,r;
    cout<<"Which eletment delemte";
    cin>>l>>r;
    l1.LeftRight(l,r);
    l1.print();
    return 0;

}