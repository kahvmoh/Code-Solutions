class Node {
public:
    int val;
    Node *next;

    Node(int x = 0) {
        val = x;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    Node *head;
    Node *tail;
    int size;
    
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index >= size) 
            return -1;
        
        Node *cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node *newHead = new Node(val);
        newHead->next = head;
        head = newHead;
        if( !tail )
            tail = head;
        
        size++;
    }
    
    void addAtTail(int val) {
        Node *newTail = new Node(val);
        if (!tail) {
            head = newTail;
            tail = newTail;
        }
        else {
            tail->next = newTail;
            tail = newTail;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) 
            return;
        // add before the head
        if (index == 0) {
            addAtHead(val);
            return;
        }
        // add after the tail
        if (index == size) {
            addAtTail(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *cur = head;
        for (int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) 
            return;
        // remove the head
        if (index == 0) {
            Node *temp = head;
            head = head->next;
            delete(temp);
        }
        else {
            Node *cur = head;
            Node *prev = nullptr;
            for (int i = 0; i < index; i++) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            if( cur == tail )
                tail = prev;
            delete(cur);
        }
        size--;
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