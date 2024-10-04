class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans= 0;
        int n = skill.size();
        sort(skill.begin(), skill.end());

        long long req = skill[0] + skill[n-1];
        for(int i = 0 ; i < n/2; i++){
            if(skill[i] + skill[n-i-1] == req){
                ans += skill[i] * skill[n-i-1];
            }
            else{
                return -1;
            }
        }
        return ans;
    }
};