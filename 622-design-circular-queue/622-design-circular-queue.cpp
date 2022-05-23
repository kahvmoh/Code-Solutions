class MyCircularQueue {
public:

    int front=0;
    int rear=0;
    int count=0;
    
    vector<int>arr;
    int size;
    
    MyCircularQueue(int k) {
        size = k;
        arr.resize(size,-1);
    }
    
    bool enQueue(int value) {
        if(count == size) 
            return false;
        arr[rear] = value;
        rear = (rear + 1) % size;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(count == 0)
            return false;
        arr[front]=-1;
        front = (front + 1) % size;
        count--;
        return true;
    }
    
    int Front() {
        return arr[front];
    }
    
    int Rear() {
        return arr[(rear - 1 + size) % size];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
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