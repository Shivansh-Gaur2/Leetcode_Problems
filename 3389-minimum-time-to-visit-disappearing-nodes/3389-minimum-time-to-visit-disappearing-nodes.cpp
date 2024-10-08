class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
       // dijstras algo
        vector<vector<pair<int, int> > > graph(disappear.size());


        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
            graph[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
        }


        set<pair<int, int> > s; // (distance, node)
        s.insert(make_pair(0,0)); // 0th node having shortest distance from 0th node itself is 0.
        vector<int> distance(disappear.size(), INT_MAX);
        distance[0] = 0;


        while(!s.empty()){
            pair<int, int> p = *(s.begin());
            s.erase(s.begin());
            for(auto child: graph[p.second]){
                if( distance[p.second] < disappear[p.second] && distance[child.first] > distance[p.second] + child.second){
                    int newDistance = distance[p.second] + child.second;
                    if(s.find(make_pair(distance[child.first], child.first)) != s.end()){
                        s.erase(s.find(make_pair(distance[child.first], child.first)));
                    }
                    distance[child.first] = newDistance;
                    s.insert(make_pair(newDistance, child.first));
                }
            }


        }
        
        for(int i=0;i<disappear.size();i++){
            if(distance[i] >= disappear[i]){
                distance[i] = -1;            
            }
        }

        return distance;



    }
};