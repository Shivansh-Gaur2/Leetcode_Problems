class Solution {
    using ll = long long;
    using pll = pair<ll, int>;
    ll INF = (1LL << 60);

    vector<ll> dijkstra(int n, const vector<vector<pair<int, int>>>& g,
                        int src) {
        vector<ll> dist(n, INF);
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u])
                continue;
            for (auto [v, w] : g[u])
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
        }
        return dist;
    }

public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {

        vector<vector<pair<int, int>>> g(n), rg(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            rg[v].push_back({u, w});
        }

        auto d1 = dijkstra(n, g, src1);
        auto d2 = dijkstra(n, g, src2);
        auto dt = dijkstra(n, rg, dest);

        ll ans = INF;
        for (int v = 0; v < n; ++v)
            if (d1[v] < INF && d2[v] < INF && dt[v] < INF)
                ans = min(ans, d1[v] + d2[v] + dt[v]);

        return ans == INF ? -1 : ans;
    }
};
