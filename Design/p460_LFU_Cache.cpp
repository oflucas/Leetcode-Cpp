class LFUCache {
    map<int, list<int>> used; // freq - list of key
    map<int, tuple<int, int, list<int>::iterator>> h; // key - tuple<value, freq, list element>
    int max_size;
    int min_freq;
    
public:
    LFUCache(int capacity) {
        max_size = capacity;
        min_freq = 0;
    }
    
    int get(int key) {
        auto it = h.find(key);
        if (it == h.end()) return -1;
        
        auto& tp = it->second;
        int value = std::get<0>(tp);
        int freq = std::get<1>(tp)++;
        auto& li = std::get<2>(tp);
        
        used[freq].erase(li);
        li = push_front(freq + 1, key).begin();
        
        if (used[min_freq].size() == 0)
            min_freq++;
            
        return value;
    }
    
    void put(int key, int value) {
        if (max_size <= 0)
            return;
        
        int res = get(key);
        if (res != -1) {
            std::get<0>(h[key]) = value;
            return;
        }
        
        if (h.size() >= max_size) {
            h.erase(used[min_freq].back());
            used[min_freq].pop_back();
        }
        
        min_freq = 1;
        list<int>::iterator li = push_front(1, key).begin();
        h.emplace(key, make_tuple(value, 1, li));
    }
    
    list<int>& push_front(int freq, int elem) {
        if (used.find(freq) == used.end())
            used.emplace(freq, list<int>());
        used[freq].push_front(elem);
        return used[freq];
    }
};

/**
 *  * Your LFUCache object will be instantiated and called as such:
 *   * LFUCache obj = new LFUCache(capacity);
 *    * int param_1 = obj.get(key);
 *     * obj.put(key,value);
 *      */
