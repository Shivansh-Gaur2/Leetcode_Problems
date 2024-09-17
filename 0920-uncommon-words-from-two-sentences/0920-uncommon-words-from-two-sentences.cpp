class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + ' ' + s2;
        unordered_map<string , int> ump;

        string word = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                word += s[i];
            }
            else{
                ump[word]++;
                word = "";
            }
        }
        ump[word]++;

        vector<string> ans;

        for(auto it : ump){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};