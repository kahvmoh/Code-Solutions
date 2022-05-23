class MyCircularDeque {
public:
    int front=0;
    int rear=0;
    int count=0;
    
    vector<int>arr;
    int size;
    
    MyCircularDeque(int k) {
        size = k;
        rear = k - 1;
        arr.resize(k, -1);
    }
    
    bool insertFront(int value) {
        if( size == count )
            return false;
        front = ((front - 1) + size) % size;
        arr[front] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if( size == count )
            return false;
        rear = (rear + 1) % size;
        arr[rear] = value;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if( count == 0 )
            return false;
        front = (front + 1 ) % size;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if( count == 0 )
            return false;
        rear = (rear - 1 + size) % size;      
        count--;
        return true;
    }
    
    int getFront() {
        if( count > 0)
            return arr[front];
        return -1; 
    }
    
    int getRear() {
        if( count > 0)
            return arr[rear];
        return -1;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */