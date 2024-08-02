class LRUCache {
public:
    // Doubly Linked List Node
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            next = prev = nullptr;
        }
    };
    
    Node* dummyHead;
    Node* dummyTail;
    int cacheCapacity;
    unordered_map<int, Node*> cacheMap;

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        node->next = node->prev = nullptr;
    }

    void insertAtHead(Node* node) {
        Node* nextNode = dummyHead->next;
        dummyHead->next = node;
        node->prev = dummyHead;
        node->next = nextNode;
        nextNode->prev = node;
    }

    LRUCache(int capacity) {
        dummyHead = new Node(-1, -1);
        dummyTail = new Node(-1, -1);
        cacheCapacity = capacity;
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* node = cacheMap[key];
            removeNode(node);
            insertAtHead(node);
            return node->value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* node = cacheMap[key];
            node->value = value;
            removeNode(node);
            insertAtHead(node);
        } else {
            if (cacheMap.size() == cacheCapacity) {
                Node* lruNode = dummyTail->prev;
                cacheMap.erase(lruNode->key);
                removeNode(lruNode);
                delete lruNode;
            }
            Node* newNode = new Node(key, value);
            insertAtHead(newNode);
            cacheMap[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */