class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, maxi = 0;

        for(int i = 0 ; i < gain.size(); i++){
            sum += gain[i];
            maxi = max(maxi , sum);
        }
        return maxi;
    }
};