class Solution {
public:
    void topoSort(int node, vector<bool>& visited, unordered_map<int, list<int>>& adj, stack<int>& st) {
        visited[node] = true;
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                topoSort(neigh, visited, adj, st);
            }
        }
        st.push(node);
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, list<int>> adj;
        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }
        vector<bool> visited(numCourses, false);
        stack<int> st;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                topoSort(i, visited, adj, st);
            }
        }

        vector<vector<bool>> dp(numCourses, vector<bool>(numCourses, false));

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (int neigh : adj[node]) {
                dp[node][neigh] = true; 
                for (int i = 0; i < numCourses; i++) {
                    if (dp[i][node]) {
                        dp[i][neigh] = true;
                    }
                }
            }
        }

        vector<bool> ans;
        for (auto& query : queries) {
            ans.push_back(dp[query[0]][query[1]]);
        }

        return ans;
    }
};
