class LRUCache {
private:
    int size;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    list<pair<int, int>> myList;
    
    // Puts the given key to the front
    void updateList(int key, int value) {
        if (hash.count(key)) {
            myList.erase(hash[key]);
        }
        myList.push_front(make_pair(key, value));
        hash[key] = myList.begin();
    }

    // Removes the old key from the myList
    void evict() {
        hash.erase(myList.back().first);
        myList.pop_back();
    }

public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (hash.count(key) == 0) {
            return -1;
        }
        updateList(key, hash[key]->second);
        return hash[key]->second;
    }
    
    void put(int key, int value) {
        // If the myList is full and a new key is to be added, evict the oldest key
        if (myList.size() == size && hash.count(key) == 0) {
            evict();
        }
        updateList(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */