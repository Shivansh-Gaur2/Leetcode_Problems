class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>ump;

        for(int i = 0 ; i < arr.size(); i++){
            ump[arr[i]]++;
        }

        for(int i = 0 ; i < target.size(); i++){
            if(ump.count(target[i]) == 0 || ump[target[i]] == 0){
                return false;
            }
             
            ump[target[i]]--;
            
        }

        return true;
    }
};