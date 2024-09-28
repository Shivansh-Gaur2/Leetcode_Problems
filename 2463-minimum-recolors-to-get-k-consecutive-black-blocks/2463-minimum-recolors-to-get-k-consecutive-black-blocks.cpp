class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        int blacks = 0;
        int left = 0;
        for(int right = 0; right< blocks.size(); right++){
            if(blocks[right] == 'B'){
                blacks++;
            }
            while(right - left + 1 > k){
                if(blocks[left] == 'B'){
                    blacks--;
                }
                left++;
            }
            ans = min(ans, k - blacks);
        } 
        return ans;
    }
};