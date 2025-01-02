class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);
        set<char> st = {'a', 'e' ,'i' , 'o' , 'u'};

        for(int i = 0; i < n; i++){
            if(st.find(words[i][0]) != st.end() && st.find(words[i][words[i].size()-1]) != st.end()){
                prefix[i+1] = prefix[i] + 1;
            }
            else{
                prefix[i+1] = prefix[i];
            }
        }

        vector<int> ans; 
        for(auto it : queries){
            int start = it[0];
            int end = it[1];
            ans.push_back(prefix[end+1] - prefix[start]);
        }

        return ans;

    }
};