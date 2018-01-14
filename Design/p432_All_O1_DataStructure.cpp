class AllOne {
    typedef pair<int, list<string>::iterator> ValueItem;
    unordered_map<string, ValueItem> hv;
    map<int, list<string>> rank;
    
public:
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (hv.find(key) == hv.end()) {
            rank[1].push_front(key);
            hv.emplace(key, make_pair(1, rank[1].begin()));
        } else 
            safe_update(key, +1);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (hv.find(key) == hv.end())
            return;
        
        safe_update(key, -1);
        
        if (hv[key].first < 1) {
            rank.erase(0);
            hv.erase(key);
        }
    }
    
    void safe_update(string key, int d) {
        ValueItem& vi = hv[key];
            rank[vi.first].erase(vi.second);
            if (rank[vi.first].empty())
                rank.erase(vi.first);
            vi.first += d;
            rank[vi.first].push_front(key);
            vi.second = rank[vi.first].begin();
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return rank.rbegin() == rank.rend() ? "" : rank.rbegin()->second.front();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return rank.begin() == rank.end() ? "" : rank.begin()->second.front();
    }
};

/**
 *  * Your AllOne object will be instantiated and called as such:
 *   * AllOne obj = new AllOne();
 *    * obj.inc(key);
 *     * obj.dec(key);
 *      * string param_3 = obj.getMaxKey();
 *       * string param_4 = obj.getMinKey();
 *        */
