class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> ump;
        for(auto ch : allowed){
            ump[ch]++;
        }

        int cnt = 0;

        for(auto it : words){
            bool flag = false;
            for(auto ch : it){
                if(ump.find(ch) == ump.end()){
                    flag = true;
                    break;
                }
                
            }
            if(!flag){
                cnt++;
            }
        }
        return cnt;
    }
};