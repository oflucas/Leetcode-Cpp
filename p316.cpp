class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last[26];
        bool used[26];
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
            used[s[i] - 'a'] = false;
        }
        
        vector<char> st;
        for (int i = 0; i < s.size(); i++) 
            if (!used[s[i] - 'a']) {
                while (!st.empty() && st.back() > s[i] && last[st.back() - 'a'] > i) {
                    used[st.back() - 'a'] = false;
                    st.pop_back();
                }
                st.push_back(s[i]);
                used[s[i] - 'a'] = true;
            }
        return string(st.begin(), st.end());
    }
};
