class Solution {
public:
    typedef priority_queue<string, vector<string>, greater<string>> Pq;
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        auto g = makeGraph(tickets);
        list<string> path;
        dfs("JFK", g, path);
        return vector<string>(path.begin(), path.end());
    }
    
    void dfs(string start, unordered_map<string, Pq>& g, list<string>& path) {
        auto iter = g.find(start);
        if (iter != g.end())
            while (!iter->second.empty()) {
                auto next = iter->second.top();
                iter->second.pop();
                dfs(next, g, path);
            }
        path.push_front(start);
    }
    
    unordered_map<string, Pq> makeGraph(const vector<pair<string, string>>& tickets) {
        unordered_map<string, Pq> g;
        for (const auto& e : tickets) {
            g[e.first].push(e.second);
        }
        return g;
    }
};
