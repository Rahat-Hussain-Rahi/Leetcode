#include <iostream>
using namespace std;
class MyCircularQueue
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
    MyCircularQueue(int k) : front{-1}, rear{-1}, size{-1}, capacity{k}
    {
        arr = new int[k];
    }

    bool enQueue(int value)
    {
        if (size == capacity - 1)
        {
            return false;
        }
        ++size;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        if (front == -1)
        {
            front = 0;
        }
        return true;
    }

    bool deQueue()
    {
        if (!isEmpty())
        {
            --size;
            front = (front + 1) % capacity;
            return true;
        }
        return false;
    }

    int Front()
    {
        if (!isEmpty())
        {
            return arr[front];
        }
        return -1;
    }

    int Rear()
    {
        if (!isEmpty())
        {
            return arr[rear];
        }
        return -1;
    }

    bool isEmpty()
    {
        return size == -1;
    }

    bool isFull()
    {
        return size == capacity - 1;
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