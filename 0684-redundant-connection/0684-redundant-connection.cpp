class Solution {
public:
    vector<int> isCyclicBFS(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj) {
        unordered_map<int, int> parent;
        parent[node] = -1;
        vis[node] = true;
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto neighbour : adj[front]) {
                if (vis[neighbour] && neighbour != parent[front]) {
                    return {front, neighbour};
                } else if (!vis[neighbour]) {
                    q.push(neighbour);
                    vis[neighbour] = true;
                    parent[neighbour] = front;
                }
            }
        }
        return {}; 
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> vis;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vis.clear(); 
            vector<int> ans = isCyclicBFS(u, vis, adj);

            if (!ans.empty()) {
                return edge;
            }
        }

        return {};
    }
};