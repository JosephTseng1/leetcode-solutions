/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        
        stack<Node*> tracker;
        unordered_map<Node*, Node*> storage;
        
        Node* clone = new Node(node->val);
        tracker.push(node);
        storage[node] = clone;
       
        while (!tracker.empty()) {
            Node *current = tracker.top();
            
            tracker.pop();
            
            for (int i = 0; i < current->neighbors.size(); i++) {
                if (storage.find(current->neighbors[i]) == storage.end()) {
                    Node* entry = new Node(current->neighbors[i]->val);
                    tracker.push(current->neighbors[i]);
                    storage[current->neighbors[i]] = entry;
                }
                
                storage[current]->neighbors.push_back(storage[current->neighbors[i]]);
            }
        }
        
        return clone;
    }
};
