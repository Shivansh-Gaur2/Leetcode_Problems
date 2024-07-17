class Solution {
private:
    void dfs(int node, int& nodeCnt, int& edgeCnt, vector<vector<int>>& adjLis, vector<bool>& vis) {
        vis[node] = true;
        nodeCnt++;
        edgeCnt += adjLis[node].size();
        for (auto it : adjLis[node]) {
            if (!vis[it]) {
                dfs(it, nodeCnt, edgeCnt, adjLis, vis);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjLis(n);  // Initialize adjacency list with n nodes
        vector<bool> vis(n, false);

        // Build the adjacency list
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            adjLis[u].push_back(v);
            adjLis[v].push_back(u);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int nodeCnt = 0, edgeCnt = 0;
            if (!vis[i]) {
                dfs(i, nodeCnt, edgeCnt, adjLis, vis);
                if (nodeCnt * (nodeCnt - 1) == edgeCnt) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
