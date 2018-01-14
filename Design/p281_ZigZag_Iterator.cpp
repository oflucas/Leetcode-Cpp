class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.begin() != v1.end()) q.emplace_back(v1);
        if (v2.begin() != v2.end()) q.emplace_back(v2);
    }

    int next() {
        Iter it = q.front();
        q.pop_front();
        int res = *(it.i++);
        if (!it.isEnd())
            q.push_back(it);
        return res;
    }

    bool hasNext() {
        return !q.empty();
    }

private:
    struct Iter {
        vector<int>::iterator i, e;
        
        Iter(vector<int>& vec): i(vec.begin()), e(vec.end()) {}
        
        bool isEnd() { return i == e; } 
    };
    
    list<Iter> q;
};

/**
 *  * Your ZigzagIterator object will be instantiated and called as such:
 *   * ZigzagIterator i(v1, v2);
 *    * while (i.hasNext()) cout << i.next();
 *     */
