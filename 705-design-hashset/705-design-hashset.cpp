class MyHashSet {
private:
    vector<int>* mySet;
public:
    MyHashSet() {
        mySet = new vector<int>;
    }

    void add(int key) {
        if(!contains(key))
            mySet->push_back(key);
    }

    void remove(int key) {
        for(int i = 0; i < mySet->size(); ++i){
            if((*mySet)[i] == key)
                mySet->erase(mySet->begin() + i);
        }

    }

    bool contains(int key) {
        for(auto element : *mySet)
            if(element == key)
                return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */