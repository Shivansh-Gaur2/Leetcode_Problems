class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        q.push(0);
        vector<bool> v(rooms.size(), false);
        while(!q.empty()){
            int node = q.front();
            v[node] = true;
            for(auto it : rooms[node]){
                if(!v[it]){
                    q.push(it);
                }
            }
            q.pop();
        }
        for(int i =0 ; i < v.size(); i++){
            if(!v[i]){
                return false;
            }
        }
        return true;
    }
};