class Solution {
public:
    typedef pair<int, int> Edge;
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Edge> edges, ans;
        for (const auto& building : buildings) {
            edges.emplace_back(building[0], building[2]);
            edges.emplace_back(building[1], -building[2]); // neg symbolizes end
        }        
        sort(edges.begin(), edges.end());
        
        map<int, int, greater<int>> max_heights;
        vector<vector<int>> loc_heights;
        max_heights[0] = 1;
        for (const auto& e : edges) {
            auto iter = max_heights.find(abs(e.second));
            if (e.second > 0) {
                if (iter != max_heights.end())
                    max_heights[e.second]++;
                else
                    max_heights[e.second] = 1;
            } else {
                if (iter->second <= 1)
                    max_heights.erase(iter);
                else
                    max_heights[-e.second]--;
            }
            
            iter = max_heights.begin();
            if (loc_heights.empty() || loc_heights.back()[0] < e.first)
                loc_heights.emplace_back(vector<int>{e.first, iter->first});
            else
                loc_heights.back()[1] = iter->first;
            }
            
        for (int i = 0; i < loc_heights.size(); i++)
            if (i == 0 || loc_heights[i][1] != loc_heights[i - 1][1])
                ans.emplace_back(loc_heights[i][0], loc_heights[i][1]);
        
        return ans;
    }
};
