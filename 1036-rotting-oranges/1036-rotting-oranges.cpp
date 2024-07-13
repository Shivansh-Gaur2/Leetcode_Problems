class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis = grid;

        queue<pair<int, int>> q;
        int cnt = 0;
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 2){
                    q.push({i, j});
                }
                if(vis[i][j] == 1){cnt++;}
            }
        }
        if(cnt ==0){
            return 0;
        }
        if(q.empty()) return -1;
        int mins = -1;
        vector<int> dx= {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;

                for(int k = 0; k < 4; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && vis[ni][nj] == 1){
                        vis[ni][nj] = 2;
                        cnt--;
                        q.push({ni, nj});
                    }
                }
            }
            mins++;
        }

        if(cnt == 0) return mins;
        return -1;
    }
};