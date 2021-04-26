struct entry {
    int val;
    list<int>::iterator ptr;
};

class LRUCache {
public:
    int size;
    unordered_map<int, entry> search;
    list<int> items;
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (search.find(key) != search.end()) {
            items.erase(search[key].ptr);
            items.push_front(key);
            search[key].ptr = items.begin();
            return search[key].val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (search.find(key) != search.end()) {
            items.erase(search[key].ptr);
        }
        if (items.size() == size) {
            search.erase(items.back());
            items.pop_back();
        }
        items.push_front(key);
        search[key] = {value, items.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
