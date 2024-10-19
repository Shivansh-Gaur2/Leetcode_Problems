class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());

    vector<vector<int>> ans;

    ans.push_back(points[0]);

    for(int i = 1 ; i < points.size(); i++){
        vector<int> &curr = ans.back();

        if(points[i][0] > curr[1]){
            ans.push_back(points[i]);
        }
        else{
            curr[1] = min(points[i][1], curr[1]);
        }
    }
    return ans.size();
    }
};
