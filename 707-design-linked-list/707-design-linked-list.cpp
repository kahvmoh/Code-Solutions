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
        
        Node *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
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
        if (!head && !tail) {
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
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) 
            return;
        if (index == 0) {
            Node *temp = head;
            head = head->next;
            delete(temp);
        }
        else if (index == size - 1) {
            Node *temp = head;
            //find the node before tail
            while(temp->next != tail) {
                temp = temp->next;
            }
            delete(tail);
            tail = temp;
        }
        else {
            Node *temp = head;
            Node *prev = nullptr;
            for (int i = 0; i < index; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete(temp);
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