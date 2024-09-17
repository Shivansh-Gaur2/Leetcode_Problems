class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> ump;
        string word = "";
        for(int i = 0 ; i < s1.size(); i++){
            if(s1[i] != ' '){
                word += s1[i];
            }
            else{
                ump[word]++;
                word = "";

            }
        }
        ump[word]++;
        word = "";

        for(int i = 0; i < s2.size(); i++){
            if(s2[i] != ' '){
                word += s2[i];
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