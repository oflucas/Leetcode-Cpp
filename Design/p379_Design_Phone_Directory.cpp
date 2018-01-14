class PhoneDirectory {
public:
    /** Initialize your data structure here
 *         @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; set_.insert(i++));
    }
    
    /** Provide a number which is not assigned to anyone.
 *         @return - Return an available number. Return -1 if none is available. */
    int get() {
        int res = set_.empty() ? -1 : *(set_.begin());
        if (res >= 0)
            set_.erase(res);
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return set_.find(number) != set_.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        set_.insert(number);
    }
    
private:
    unordered_set<int> set_;
};

/**
 *  * Your PhoneDirectory object will be instantiated and called as such:
 *   * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 *    * int param_1 = obj.get();
 *     * bool param_2 = obj.check(number);
 *      * obj.release(number);
 *       */
