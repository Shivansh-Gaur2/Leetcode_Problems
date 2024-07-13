class Solution {
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        queue<pair<int, int>> q;

        q.push({entrance[0], entrance[1]});

        int lev = 0;

        grid[entrance[0]][entrance[1]] = '+';

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                if (!(i == entrance[0] && j == entrance[1]) &&
                    (i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
                    return lev;
                }

                for(int k = 0; k < 4 ; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] != '+'){
                        grid[ni][nj] = '+';
                        q.push({ni, nj});
                    }
                }
            }
            lev++;
        }
        return -1;
    }
};