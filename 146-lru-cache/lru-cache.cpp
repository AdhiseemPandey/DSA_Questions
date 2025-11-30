class LRUCache {
public:
    // Doubly linked list node class
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> m;

    // Add node right after head
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // Remove a node
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int res = resNode->val;
            // Move node to front
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;  // update map
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* existingNode = m[key];
            deleteNode(existingNode);
            m.erase(key);
        }
        if (m.size() == cap) {
            // remove least recently used (before tail)
            Node* lru = tail->prev;
            deleteNode(lru);
            m.erase(lru->key);
            delete lru; // free memory
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */