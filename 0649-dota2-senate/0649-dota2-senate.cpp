class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>rad;
        queue<int>dire;
        int n = senate.size();

        for(int i = 0 ; i < senate.size(); i++){
            if(senate[i] == 'R'){
                rad.push(i);
            }
            else{
                dire.push(i);
            }
        }

        while(!rad.empty() && !dire.empty()){
            int ridx = rad.front();
            int didx = dire.front();

            if(ridx < didx){
                rad.push(ridx+n);
            }
            else{
                dire.push(didx+n);
            }
            rad.pop();
            dire.pop();
        }
        return !rad.empty() ? "Radiant" : "Dire";
    }
};