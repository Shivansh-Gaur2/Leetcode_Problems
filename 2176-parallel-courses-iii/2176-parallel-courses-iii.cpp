class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> inDegree(n + 1, 0);
        vector<vector<int>> adjList(n + 1);
        vector<int> dp(n + 1, 0);

        for (auto& it : relations) {
            int u = it[0], v = it[1];
            adjList[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                dp[i] = time[i - 1];
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int next : adjList[curr]) {
                dp[next] = max(dp[next], dp[curr] + time[next - 1]); 
                if (--inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};