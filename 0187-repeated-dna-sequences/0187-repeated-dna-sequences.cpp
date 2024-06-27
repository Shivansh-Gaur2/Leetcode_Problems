class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;

        unordered_map<string, int> ump;

        int left = 0, right = 9;
        while(right < s.size()){
            cout << s.substr(left, 10) << endl;
            string str = s.substr(left, 10);
            if(ump.find(str) != ump.end()){
                if(ump[str] > 0){
                    ans.push_back(str);
                }
                ump[str]--;
                cout << ump[str] << endl;
            }
            else{
            ump[str]++;
            }
            left++;
            right++;
        }

        return ans;
    }
};