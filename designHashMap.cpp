struct Node {
    int key;
    int value;
    Node* next;
    Node (int k, int v) {
        key = k;
        value = v;
        next = NULL;
    };
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    Node* map[100000];
    
    MyHashMap() {
        for (int i = 0; i < 100000; i++) {
            map[i] = NULL;
        }
    }
   
    /** value will always be non-negative. */
    void put(int key, int value) {
        if (map[key % 100000] == NULL) {
            map[key % 100000] = new Node(key, value);
        } else {
            Node* current = map[key % 100000];
            Node* prev = NULL;
            bool found = false;
            while (current) {
                if (current->key == key) {
                    current->value = value;
                    found = true;
                    return;
                }
                prev = current;
                current = current->next;
            }
            if (!found) {
                prev->next = new Node(key, value);
            }
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (map[key % 100000] == NULL) {
            return -1;
        } else {
            Node* current = map[key % 100000];
            
            while (current) {
                if (current->key == key) {
                    return current->value;
                }
                current = current->next;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if (map[key % 100000] == NULL) {
            return;
        }
        Node* current = map[key % 100000];
        Node* prev = NULL;
        while (current) {
            if (current->key == key) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    map[key % 100000] = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
