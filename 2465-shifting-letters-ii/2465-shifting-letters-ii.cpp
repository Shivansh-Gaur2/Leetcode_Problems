class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> list(n +1 , 0);

        for(auto it : shifts){
            int start = it[0];
            int end = it[1];
            int dir = it[2];

            if(dir == 1){
                list[start] += 1;
                if(end +1 < n){
                    list[end+1] -=1;
                }
            }
            else{
                list[start] -= 1;
                if(end + 1 < n){
                    list[end + 1] +=1;
                }
            }
        }

        int netShift= 0;
        for(int i = 0 ; i < list.size(); i++){
            netShift += list[i];
            netShift = (netShift % 26 + 26)%26;
            s[i] = (s[i] - 'a' + netShift) % 26 + 'a';
        }
        return s;
    }
};