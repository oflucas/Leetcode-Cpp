class Solution {
public:
    int findMaximumXOR(vector<int>& a) {
      int n = a.size();
      TrieTree r;
      int ans = 0;
      for (auto num : a) {
        int xor_ret = r.insert(num);
        ans = max(ans, xor_ret);
      }
      return ans;         
    }

struct TrieNode {
  TrieNode* next[2];
  TrieNode(): next() {}
  ~TrieNode() {
    for (auto n: next)
      if (n)
        delete n;
  }
};
    
class TrieTree {
private:
  TrieNode* root;
    
public:
  TrieTree(): root(new TrieNode()) {}
    
  int insert(int num) {
    TrieNode *i = root, *j = root;
    int res = 0;
    for (int k = 31; k >= 0; k--) {
      int mask = 1 << k;
      int b = (mask & num) > 0 ? 1 : 0;
        
      if (i->next[b] == NULL)
        i->next[b] = new TrieNode();
      i = i->next[b];  
        
      if (j->next[1 - b]) {
        res += mask;
        j = j->next[1 - b];
      } else
        j = j->next[b];
    }
    return res;
  }
    
  ~TrieTree() {
    delete root;
  }
};

};
