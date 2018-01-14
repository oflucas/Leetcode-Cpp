class RandomizedSet {
    vector<int> l;
    unordered_map<int, int> pos;
    
public:
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (pos.find(val) != pos.end())
            return false;
        l.emplace_back(val);
        pos.emplace(val, l.size() - 1);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (pos.find(val) == pos.end())
            return false;
        l[pos[val]] = l.back();
        pos[l.back()] = pos[val];
        l.pop_back();
        pos.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return l[rand() % l.size()];
    }
};

/**
 *  * Your RandomizedSet object will be instantiated and called as such:
 *   * RandomizedSet obj = new RandomizedSet();
 *    * bool param_1 = obj.insert(val);
 *     * bool param_2 = obj.remove(val);
 *      * int param_3 = obj.getRandom();
 *       */
