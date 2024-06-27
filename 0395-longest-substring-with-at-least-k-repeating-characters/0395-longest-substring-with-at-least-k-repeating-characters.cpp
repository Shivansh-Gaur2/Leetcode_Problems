class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size()<k) return 0;
        if(k==1) return s.size();
        vector<int> freq(26,0);
        for(auto it:s) freq[it-'a']++;
        bool valid=1;
        int maxi=0, i=0, j=0;
        for(j=0;j<s.size();j++){
            if(freq[s[j]-'a']<k){
                maxi=max(maxi, longestSubstring(s.substr(i,j-i),k));
                i=j+1;
                valid=0;
            }
        }
        if(valid) return s.size();
        //for remaining string
        maxi=max(maxi, longestSubstring(s.substr(i),k));
        return maxi;
    }
};