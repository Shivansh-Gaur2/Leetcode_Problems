class Solution {
public:
    void topoSort(int node, stack<int>& st, unordered_map<int, list<int>>& adj, vector<bool>& vis) {
        vis[node] = true;  
        for (auto neigh : adj[node]) {
            if (!vis[neigh]) {
                topoSort(neigh, st, adj, vis);
            }
        }
        st.push(node);
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, list<int>> adj;
        int n = quiet.size(); 

        for (int i = 0; i < richer.size(); i++) {
            int u = richer[i][0];
            int v = richer[i][1];
            adj[u].push_back(v); 
        }

        vector<bool> visited(n, false);
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                topoSort(i, s, adj, visited);
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = i;  
        }

        while (!s.empty()) {
            int node = s.top();
            s.pop();
            for (auto neighbor : adj[node]) {
                if (quiet[ans[node]] < quiet[ans[neighbor]]) {
                    ans[neighbor] = ans[node];
                }
            }
        }

        return ans;
    }
};
