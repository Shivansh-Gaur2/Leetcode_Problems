class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        set<pair<int, int>> obs;
        int x = 0, y = 0;

        for(auto it : obstacles){
            obs.insert({it[0], it[1]});
        }
        int dist = 0;
        for(int i = 0 ; i < commands.size(); i++){
            if(commands[i] == -1){
                dir = (dir + 1)%4;
            }
            else if(commands[i] == -2){
                dir = (dir + 3) % 4;
            }
            else{
                for(int k = 0; k < commands[i] ; k++){
                    int newX = x + directions[dir].first;
                    int newY = y + directions[dir].second;

                    if(obs.find({newX, newY}) == obs.end()){
                        x= newX;
                        y = newY;
                        dist = max(dist, x*x + y*y);
                    }
                    else{
                        break;
                    }
                }
            }

        }
        return dist;
    }
};