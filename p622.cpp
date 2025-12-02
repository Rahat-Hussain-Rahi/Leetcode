class MyCircularQueue {
    int * arr;
    int capacity;
    int front;
    int rear;
public:


    MyCircularQueue(int k) 
    {
        arr=new int[k];
        capacity=k;
        front=-1;
        rear=-1;
        
    }
    
    bool enQueue(int value) 
    {
        if(front!=(rear+1)%capacity)
        {
            rear=(rear+1)%capacity;
            arr[rear]=value;
             if(front==-1)
            {
                front=0;
            }
            return true;
        }
       
        return false;
    }
    
    bool deQueue() 
    {
        if(front==-1)
        {
            return false;
        }
        if(front==rear)
            {
                front=rear=-1;
                return true;
            }
        if(front!=-1)
        {
            front=((front+1)%capacity);
            
            return true;
        }
        
        return false;
        
    }
    
    int Front() 
    {
        if(front!=-1)
        {
            return arr[front];
        }
        return -1;
        
    }
    
    int Rear() 
    {
        if(rear!=-1)
        {
            return arr[rear];
        }
        return -1;
        
    }
    
    bool isEmpty() 
    {
        return front==-1;
        
    }
    
    bool isFull() 
    {
        return ((rear+1)%capacity)==front;  
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */