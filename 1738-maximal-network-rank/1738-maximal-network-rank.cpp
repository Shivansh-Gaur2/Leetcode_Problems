class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0);
        unordered_map<int, unordered_set<int>> directConnections;

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            indegree[u]++;
            indegree[v]++;
            directConnections[u].insert(v);
            directConnections[v].insert(u);
        }

        int maxi = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int net = indegree[i] + indegree[j];
                if (directConnections[i].find(j) != directConnections[i].end()) {
                    net--;
                }
                maxi = max(maxi, net);
            }
        }
        return maxi;
    }
};
