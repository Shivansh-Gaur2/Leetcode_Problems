class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0;
        int p2 = 0;
        string ans = "";

        while(p1 < word1.size() && p2 < word2.size()){
            ans += word1[p1];
            ans+= word2[p2];
            p1++;
            p2++;
        }
        if(p1 < word1.size()){
            while(p1 != word1.size()){
                ans+= word1[p1];
                p1++;
            }
        }
        if(p2 < word2.size()){
            while(p2 != word2.size()){
                ans+= word2[p2];
                p2++;
            }
        }

        return ans;
    }
};