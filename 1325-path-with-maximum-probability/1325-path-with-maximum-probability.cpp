#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0; 
        
        set<pair<double, int>> pq;
        pq.insert({1.0, start_node});
        
        while (!pq.empty()) {
            auto it = prev(pq.end());
            double prob = it->first;
            int node = it->second;
            pq.erase(it);
            if (node == end_node) return prob;
            for (auto& [neighbor, edgeProb] : adj[node]) {
                double newProb = prob * edgeProb;
                if (newProb > maxProb[neighbor]) {
                    pq.erase({maxProb[neighbor], neighbor});
                    maxProb[neighbor] = newProb;
                    pq.insert({newProb, neighbor});
                }
            }
        }
        
        return 0.0;
    }
};
