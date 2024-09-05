class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if(!bankSet.count(endGene)){
            return -1;
        }

        unordered_set<string> visited;
        queue<pair<string, int>> q;

        q.push({startGene, 0});

        visited.insert(startGene);

        while(!q.empty()){
            auto [currGene , mutat] = q.front();
            q.pop();

            if(currGene == endGene){
                return mutat;
            }

            for(int i = 0 ; i < currGene.size(); i++){
                string nexGene = currGene;
                for(auto ch : {'A', 'C' , 'G', 'T'}){
                    nexGene[i]= ch;
                    if(bankSet.count(nexGene) && !visited.count(nexGene)){
                        visited.insert(nexGene);
                        q.push({nexGene, mutat+1});
                    }
                }
            }
        }
        return -1;
    }
};