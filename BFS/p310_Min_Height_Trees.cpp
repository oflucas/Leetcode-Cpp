class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_set<int> d[n];
        for (const auto& edge : edges) {
            d[edge.first].insert(edge.second);
            d[edge.second].insert(edge.first);
        }
        
        queue<int> *q = new queue<int>(), *p = new queue<int>();
        for (int i = 0; i < n; i++)
            if (d[i].size() <= 1)
                q->push(i);

        while (n > 2) {
            for (; !q->empty(); q->pop()) {
                int i = q->front();
                for (const auto& j : d[i]) {
                    d[j].erase(i);
                    n--;
                    if (d[j].size() == 1)
                        p->push(j);
                }
            }
            auto t = q;
            q = p;
            p = t;
        }
        
        vector<int> ans;
        for (; !q->empty(); q->pop())
            ans.push_back(q->front());
        
        delete p, q;
        
        return ans;
    }
};
