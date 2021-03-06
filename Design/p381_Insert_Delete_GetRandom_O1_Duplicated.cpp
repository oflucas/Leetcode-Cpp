class RandomizedCollection {
public:
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = false;
        if (h.find(val) == h.end())
            res = true;
        l.push_back(val);
        h[val].insert(l.size() - 1); // if key does not exist, auto construct a default one
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (h.find(val) == h.end())
            return false;
            
        if (val == l.back())
            h[val].erase(l.size() - 1);
        else {
            const int pos = *(h[val].begin());
            l[pos] = l.back();
            h[l.back()].erase(l.size() - 1);
            h[l.back()].insert(pos);
            h[val].erase(pos);
        }
        l.pop_back();
        if (h[val].empty())
            h.erase(val);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return l[rand() % l.size()];
    }
    
private:
    unordered_map<int, unordered_set<int>> h;
    vector<int> l;
};

/**
 *  * Your RandomizedCollection object will be instantiated and called as such:
 *   * RandomizedCollection obj = new RandomizedCollection();
 *    * bool param_1 = obj.insert(val);
 *     * bool param_2 = obj.remove(val);
 *      * int param_3 = obj.getRandom();
 *       */
