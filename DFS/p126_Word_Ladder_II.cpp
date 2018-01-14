class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string, unordered_set<string>> path;
        unordered_map<string, int> depth;
        for (auto& i : wordList)
            depth[i] = wordList.size() + 1;
        depth[beginWord] = 0;
        
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            string s = q.front();

            int depth_s = depth[s];
            
            for (int i = 0; i < s.length(); i++) {
                char tmp = s[i];
                for (char ch = 'a'; ch <= 'z'; ch++) if (ch != tmp) {
                    s[i] = ch;
                    if (depth.find(s) != depth.end() && depth_s + 1 <= depth[s] && !path[s].count(q.front())) {
                        depth[s] = depth_s + 1;
                        path[s].insert(q.front());
                        if (s != endWord)
                            q.push(s);
                    }
                }
                s[i] = tmp;
            }
            q.pop();
        }
        
        vector<vector<string>> ans;
        vector<string> cur;
        writeout(endWord, beginWord, cur, ans, path);
        return ans;
    }
    
    void writeout(string s, string& target, vector<string> cur, vector<vector<string>>& ans, unordered_map<string, unordered_set<string>>& path) {
        cur.push_back(s);
        if (s == target) {
            vector<string> cand;
            for (vector<string>::reverse_iterator rit = cur.rbegin(); rit != cur.rend(); rit++)
                cand.push_back(*rit);
            ans.emplace_back(cand);
        }
        
        unordered_set<string>& nexts = path[s];
        for (auto i = nexts.begin(); i != nexts.end(); i++)
            writeout(*i, target, cur, ans, path);
        cur.pop_back();
    }
};
