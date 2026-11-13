class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<string> mp = {"", "LR", "UD", "LD", "RD", "LU", "RU"};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        vis[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == m - 1 && c == n - 1) return true;
            
            string curr = mp[grid[r][c]];
            for (char ch : curr) {
                int nr = r, nc = c;
                char needed;
                
                if (ch == 'U') { nr = r - 1; needed = 'D'; }
                else if (ch == 'D') { nr = r + 1; needed = 'U'; }
                else if (ch == 'L') { nc = c - 1; needed = 'R'; }
                else if (ch == 'R') { nc = c + 1; needed = 'L'; }
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc]) continue;
                string next = mp[grid[nr][nc]];
                if (next[0] == needed || next[1] == needed) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        
        return false;
    }
};