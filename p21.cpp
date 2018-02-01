class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> order;
        vector<int> inDegree(numCourses, 0);
        
        for (const auto& edge : prerequisites)
            inDegree[edge.first]++;
        
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0)
                order.push_back(i);
        
        for (int i = 0; i < order.size(); i++)
            for (const auto& edge : prerequisites)
                if (edge.second == order[i])
                    if (--inDegree[edge.first] == 0)
                        order.push_back(edge.first);
        
        return order.size() == numCourses ? order : vector<int>();
    }
    
    vector<int> findOrder_DFS(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> order;
        vector<bool> visited(numCourses, false), visiting(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!dfs(i, prerequisites, order, visited, visiting))
                return vector<int>();
        return order;
    }
    
    bool dfs(int start, const vector<pair<int, int>>& prerequisites, vector<int>& order, vector<bool>& visited, vector<bool>& visiting) {
        if (visiting[start])
            return false;
        
        if (visited[start])
            return true;
        
        visiting[start] = true;
        for (const auto& e : prerequisites)
            if (e.first == start)
                if (!dfs(e.second, prerequisites, order, visited, visiting))
                    return false;
        
        order.push_back(start);
        visiting[start] = false;
        visited[start] = true;
        return true;
    }
};
