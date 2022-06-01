struct LLNode{
    int key, val;
    LLNode *prev, *next;
    LLNode(int k = 0, int v = 0, LLNode* p = NULL, LLNode* n = NULL){
        key = k;
        val = v;
        prev = p;
        next = n;
    }
};

class doublyLinkedList{
public:
    // head node will be a dummy node and don't represent any data
    // the data nodes start from the next node of the head (e.g. head->next onward is the data items)
    
    LLNode *head, *tail;
    doublyLinkedList(){
        head = new LLNode();
        tail = head;
    }
    
    inline void addToTail(int key, int val){
        tail->next = new LLNode(key, val, tail, NULL);  
        tail = tail->next;
    }
    
    inline void moveToTail(LLNode* addr){
        if(addr != tail){
            // remove from mid
            addr->prev->next = addr->next;
            addr->next->prev = addr->prev;
            
            // add to tail
            addr->prev = tail;
            addr->next = NULL;
            tail = tail->next = addr;
        }
    }
    
    inline void remove(LLNode* addr){
        // remove the node
        addr->prev->next = addr->next;
        if(addr->next)
            addr->next->prev = addr->prev;
        
        // check wheather list is empty ? -> update tail to head
        if(!head->next)
            tail = head;
    }
};


class LRUCache {
public:
    int curr_size, max_size;    // to track the size of the cache
    vector<LLNode*> node_addr;  // hash table
    doublyLinkedList list;      // doubly linked list to store the data and preserve the order with respect to access time
    
    LRUCache(int capacity) : node_addr(10001, NULL) {
        max_size = capacity;
        curr_size = 0;
    }
    
    int get(int key) {
        // check for key in the hash table
        if(node_addr[key] == NULL) return -1;
        
        // key is there
        list.moveToTail(node_addr[key]);    // move the node to the end of list
        return node_addr[key]->val;         // return tha value
    }
    
    void put(int key, int value) {
        // key is present
        if(node_addr[key] != NULL){
            list.moveToTail(node_addr[key]);    // move the node to the end of list    
            node_addr[key]->val = value;        // update the value
            return;
        }
        
        // reached to max size
        if(curr_size == max_size){
            int key = list.head->next->key;
			list.remove(node_addr[key]);        // evict the least recently used, which is the first data item
												// (REMINDER: data items starts from head->next onwards)         
			node_addr[key] = NULL;              // mark the entry as invalid in hash table
            curr_size--;
        }
        
        curr_size++;                        // increase the size
        list.addToTail(key, value);         // add the new (key, value) to list
        node_addr[key] = list.tail;         // add the corresponding entry in hash table
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */