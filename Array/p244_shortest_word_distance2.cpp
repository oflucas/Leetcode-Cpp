class WordDistance {
    unordered_map<string, int> h;
    unordered_map<string, vector<int>> pos;
    
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); i++)
            pos[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        string key = word1 + "|" + word2;
        if (h.find(key) != h.end())
            return h[key];
        
        auto& pos_vec1 = pos[word1];
        auto& pos_vec2 = pos[word2];
        int d = abs(pos_vec1[0] - pos_vec2[0]);
        for (int i = 0, j = 0; i < pos_vec1.size() && j < pos_vec2.size(); ) {
            d = min(d, abs(pos_vec1[i] - pos_vec2[j]));
            
            if (pos_vec1[i] > pos_vec2[j])
                j++;
            else
                i++;
        }
        
        h[key] = d;
        return d;
    }
};

/**
 *  * Your WordDistance object will be instantiated and called as such:
 *   * WordDistance obj = new WordDistance(words);
 *    * int param_1 = obj.shortest(word1,word2);
 *     */
