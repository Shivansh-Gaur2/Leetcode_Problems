class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string st = "";
        for(int i = 0 ; i < word1.size(); i++){
            st += word1[i];
        }
        string t = "";
        for(int i = 0 ; i < word2.size(); i++){
            t+= word2[i];
        }

        return st == t;
    }
};