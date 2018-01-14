class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for (vector<int>& vec : vec2d)
            q.emplace(make_pair(vec.begin(), vec.end()));
    }

    int next() {
        return *(q.front().first++);
    }

    bool hasNext() {
        while (!q.empty() && q.front().first == q.front().second)
            q.pop();
        return !q.empty();
    }
    
private:
    typedef pair<vector<int>::iterator, vector<int>::iterator> IterPair;
    queue<IterPair> q;
};

/**
 *  * Your Vector2D object will be instantiated and called as such:
 *   * Vector2D i(vec2d);
 *    * while (i.hasNext()) cout << i.next();
 *     */
