class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int,Node*> cache;
    Node* head; // least
    Node* tail; // recent
    int cap;


    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void insert(Node* node) {
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node); 
            insert(node); // recently
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            Node* oldNode = cache[key];
            remove(oldNode);
        } 
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);
        

        if (cache.size() > cap) {
            // printf("%d %d\n", key, value);
            Node* del = head->next;
            remove(del);
            cache.erase(del->key);
            // free(del);
        }
    }
};
