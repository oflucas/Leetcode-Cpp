class WordDictionary {
    struct TrieNode {
        bool isWord;
        TrieNode* next[26];
        TrieNode(): isWord(false), next() { }
    };
    
    TrieNode root;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* i = &root;
        for (auto c : word) {
            if (!i->next[c - 'a'])
                i->next[c - 'a'] = new TrieNode();
            i = i->next[c - 'a'];
        }
        i->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, &root);
    }
    
    bool search(string& word, int p, TrieNode* r) {
        if (!r)
            return false;
        
        if (p == word.size())
            return r->isWord;
        
        if (word[p] != '.')
            return search(word, p + 1, r->next[word[p] - 'a']);
        else
            for (int i = 0; i < 26; i++)
                if (search(word, p + 1, r->next[i]))
                    return true;
        return false;
    }
};

/**
 *  * Your WordDictionary object will be instantiated and called as such:
 *   * WordDictionary obj = new WordDictionary();
 *    * obj.addWord(word);
 *     * bool param_2 = obj.search(word);
 *      */
