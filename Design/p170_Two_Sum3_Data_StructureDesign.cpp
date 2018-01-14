class TwoSum {
    unordered_map<int, int> hcnt;
    
public:
    /** Add the number to an internal data structure.. */
    void add(int number) {
        if (hcnt.find(number) == hcnt.end())
            hcnt[number] = 0;
        hcnt[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto& i : hcnt)
            if (hcnt.find(value - i.first) != hcnt.end())
                if (2 * i.first != value || hcnt[i.first] > 1)
                    return true;
        return false;
    }
};

/**
 *  * Your TwoSum object will be instantiated and called as such:
 *   * TwoSum obj = new TwoSum();
 *    * obj.add(number);
 *     * bool param_2 = obj.find(value);
 *      */
