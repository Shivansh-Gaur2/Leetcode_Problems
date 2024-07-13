class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> q;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }
        if(q.size() == n*n){
            return -1;
        }
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0 , 1, 0, -1};

        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr= q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for(int k = 0 ; k < 4; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 0){
                        grid[ni][nj] = 1;
                        q.push({ni, nj});
                    }
                }
            }
            ans++;
        }
        return ans-1;
    }
};