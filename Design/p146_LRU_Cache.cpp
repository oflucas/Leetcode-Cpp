class LRUCache {
    typedef list<int> key_queue;
    typedef pair<int, key_queue::iterator> record;
    typedef unordered_map<int, record> hmap;

    int capacity;
    key_queue lru_q;
    hmap cache;

public:
    LRUCache(int capacity) : capacity(capacity) { } 
        
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1; 
        refresh(it);
        return it->second.first;
    }   
        
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            if (cache.size() == capacity) {
                cache.erase(lru_q.back());
                lru_q.pop_back();
            }   
            lru_q.push_front(key);
            cache.emplace(key, make_pair(value, lru_q.begin()));
        } else {
            refresh(it);
            it->second.first = value;
        }   
    }   
        
    void refresh(hmap::iterator it) {
        int key = it->first;
        record& r = it->second;
        lru_q.erase(r.second);
        lru_q.push_front(key);
        r.second = lru_q.begin();
    }   
};

/**
 *  * Your LRUCache object will be instantiated and called as such:
 *   * LRUCache obj = new LRUCache(capacity);
 *    * int param_1 = obj.get(key);
 *     * obj.put(key,value);
 *      */
