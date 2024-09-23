class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> word(bannedWords.begin(), bannedWords.end());

        int cnt = 0;
        
        for(auto it : message){
            if(word.count(it)){
                cnt++;
                if(cnt >=2){
                    return true;
                }
            }
        }
        
        return false;
    }
};