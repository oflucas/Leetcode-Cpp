class Solution {
    class UnionSet {
    private:
        int count, n, m;
        vector<int> f;
        
        int idx(int i, int j) {
            return i * m + j;
        }
        
        int find(int i) {
            if (f[i] < 0) {
                count++;
                f[i] = i;
                return i;
            }
            
            f[i] = f[i] == i ? i : find(f[i]);
            return f[i];
        }
        
        void unite(int p, int q) {
            int i = find(p);
            int j = find(q);
            if (i == j)
                return;
            
            if (rand() % 2)
                f[i] = j;
            else
                f[j] = i;
            count--;
        }
        
    public:
        UnionSet(int n, int m): n{n}, m{m}, f(n * m, -1) {
            count = 0;
        }
        
        int Find(int i, int j) {
            return find(idx(i, j));
        }
        
        void Unite(int i, int j, int i1, int j1) {
            unite(idx(i, j), idx(i1, j1));
        }
        
        int Count() {
            return count;
        }  
    };
    
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        UnionSet us(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                if (grid[i][j] == '1') {
                    us.Find(i, j);
                    if (i > 0 && grid[i - 1][j] == '1')
                        us.Unite(i, j, i - 1, j);
                    if (j > 0 && grid[i][j - 1] == '1')
                        us.Unite(i, j, i, j - 1);
                }
        return us.Count();
    }
};
