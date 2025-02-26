class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<int> pq;

        for(int i = 0; i < n; i++){
            int lim = limits[i];
            sort(grid[i].rbegin(), grid[i].rend());
            for(int j = 0; j < lim; j++){
                pq.push(grid[i][j]);
            }
        }

        long long ans = 0;
        while(!pq.empty() && k--){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};