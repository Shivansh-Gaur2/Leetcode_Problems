class Solution {
public:
    void dfs(int node, unordered_map<int, list<int>>& adjList, vector<bool>& vis) {
        vis[node] = true;
        for (auto it : adjList[node]) {
            if (!vis[it]) {
                dfs(it, adjList, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, list<int>> adjList;
        unordered_map<int, list<int>> reverseGraph;
        
        for (auto it : invocations) {
            adjList[it[0]].push_back(it[1]);
            reverseGraph[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);
        dfs(k, adjList, vis);

        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                for (auto invoker : reverseGraph[i]) {
                    if (!vis[invoker]) {
                        vector<int> allMethods;
                        for (int j = 0; j < n; j++) {
                            allMethods.push_back(j);
                        }
                        return allMethods;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
