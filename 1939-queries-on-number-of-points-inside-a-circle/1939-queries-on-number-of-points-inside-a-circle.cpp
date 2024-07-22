class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            int cnt = 0;
            int qx = queries[i][0];
            int qy = queries[i][1];
            int qr = queries[i][2];
            int r_squared = qr * qr;
            for(int j = 0; j < points.size(); j++) {
                int px = points[j][0];
                int py = points[j][1];
                int dx = qx - px;
                int dy = qy - py;
                if(dx * dx + dy * dy <= r_squared) {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
