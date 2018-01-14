class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> order;
        vector<int> degree(numCourses);
        vector<vector<int>> edges(numCourses);
        
        for (const auto& e : prerequisites) {
            edges[e.second].push_back(e.first);
            degree[e.first]++;
        }
        
        for (int i = 0; i < numCourses; i++)
            if (degree[i] == 0)
                order.push_back(i);
        
        for (int i = 0; i < order.size(); i++) {
            int c = order[i];
            for (int j : edges[c]) {
                if (--degree[j] == 0) {
                    order.push_back(j);
                }
            }
        }
        
        return order.size() < numCourses ? vector<int>() : order;
    }
    
    vector<int> findOrderDFS(int numCourses, vector<pair<int, int>>& prerequisites) {
        list<int> order;
        vector<bool> visiting(numCourses, false), visited(numCourses, false);
        
        for (int i = 0; i < numCourses; i++)
            if (!dfs(i, visiting, visited, prerequisites, order))
                return vector<int>();
        
        return vector<int>(order.begin(), order.end());
    }

private:
    bool dfs(int i, vector<bool>& visiting, vector<bool>&visited, vector<pair<int, int>>& prerequisites, list<int>& order) {
        if (visited[i])
            return true;
        if (visiting[i])
            return false;
        visiting[i] = true;
        
        for (const auto& e : prerequisites)
            if (e.first == i)
                if (!dfs(e.second, visiting, visited, prerequisites, order))
                    return false;

        order.push_back(i);
        visiting[i] = false;
        visited[i] = true;
        return true;
    }
};
