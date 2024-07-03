class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        int res = x ^ y;

        while(res > 0){
            if(res & 1 > 0){
                cnt++;
            }
            res = res >> 1;
        }
        return cnt;
    }
};