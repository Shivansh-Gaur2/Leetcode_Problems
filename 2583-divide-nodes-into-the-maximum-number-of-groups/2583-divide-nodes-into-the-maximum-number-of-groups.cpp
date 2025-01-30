class Solution {
public:
    vector<int> gr[505];
    int color[505];
    bool isBipartite;
    vector<int> connected;

    int maxDist(int source , int totalNodes){
        vector<int> dist(totalNodes+ 1, -1);
        dist[source] = 1;
        int maxi = 1;

        queue<int> q;
        q.push(source);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto nbr : gr[node]){
                if(dist[nbr] == -1){
                    dist[nbr] = 1 + dist[node];
                    q.push(nbr);
                    maxi = max(maxi, dist[nbr]);
                }
            }
        }
        return maxi;
    }

    void dfs(int node , int currentColor = 1){
        color[node] = currentColor;
        connected.push_back(node);
        for(auto nbr : gr[node]){
            if(!color[nbr]){
                dfs(nbr, 3 - currentColor);
            }
            else if(color[nbr] == currentColor){
                isBipartite = false;
            }
        }
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        for(int i = 1; i <= n; i++){
            gr[i].clear();
        }

        memset(color, 0, sizeof color);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            gr[u].push_back(v);
            gr[v].push_back(u);
        }

        int maxGrp = 0;

        for(int i = 1; i <= n; i++){
            if(color[i] == 0){
                connected.clear();
                isBipartite = true;

                dfs(i);
                if(!isBipartite) return -1;
                int maxComponent = 0;

                for(auto node : connected){
                    maxComponent = max(maxComponent, maxDist(node, n));
                }
                maxGrp += maxComponent;
            }
        }
        return maxGrp;
    }
};