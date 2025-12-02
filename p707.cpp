class MyLinkedList;
class Node
{
    int data;
    Node* next;
    
    public:
    friend class MyLinkedList;
    Node(int m_val,Node* m_next=nullptr):data{m_val},next{m_next}{}
};
class MyLinkedList 
{
    int count;
    Node* head;

    public:
    MyLinkedList():head{nullptr} ,count{0}
    {
        
    }
    
    int get(int index) 
    {
        if(index>count)
        {
            return -1;
        }
        int i{};
            Node* pre=head;
            while((i!=index+1)&&(pre->next))
            {
                pre=pre->next;
                ++i;
            }
            if(pre)
         {
            return pre->data;
            }
         return -1;
    }
    void addAtHead(int val) 
    {
        ++count;
        Node* New=new Node(val);
        if(head==nullptr)
        {
            head=New;
            return;
        }
        New->next=head;
        head=New;
        
    }
    
    void addAtTail(int val) 
    {
        ++count;
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
    
    void addAtIndex(int index, int val) 
    {
        if(index>count)
        {
            return;
        }
        Node* New=new Node(val);
        if(head)
        {
            int i{};
            Node* pre=head;
            while((i<=index-1)&&(pre->next))
            {
                pre=pre->next;
                ++i;
            }
            if(i+1==count)
            {
                pre->next=New;
                return;
            }
            ++count;
            New->next=pre->next;
            pre->next=New;
        }
        return;
        
    }
    
    void deleteAtIndex(int index) 
    {
        if(head)
        {
            int i{};
            Node* pre=head;
            while((i<=index-1)&&(pre->next))
            {
                pre=pre->next;
                ++i;
            }
            if(pre==head)
            {
                return;
            }
            if((pre)&&(pre->next))
            {
                Node* curr=pre->next;
                pre->next=curr->next;
                delete curr;
            }
            else
            {
                delete pre->next;
                pre->next=nullptr;
            }
        
            --count;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */