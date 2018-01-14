class Trie {
    struct TrieNode {
        bool isWord;
        TrieNode* next[26];
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insert(root, word, 0);
    }
    
    void insert(TrieNode* r, string& word, int p) {
        if (p == word.length()) {
            r->isWord = true;
            return;
        }
        int ch = word[p] - 'a';
        if (!r->next[ch])
            r->next[ch] = new TrieNode();
        insert(r->next[ch], word, p + 1);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* i = trace(word);
        return i && i->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        return trace(word);
    }
    
    TrieNode* trace(string& word) {
        TrieNode* i = root;
        int p = 0, len = word.length();
        for (; p < len && i; i = i->next[word[p++] - 'a']);
        return i;
    }
};

/**
 *  * Your Trie object will be instantiated and called as such:
 *   * Trie obj = new Trie();
 *    * obj.insert(word);
 *     * bool param_2 = obj.search(word);
 *      * bool param_3 = obj.startsWith(prefix);
 *       */
