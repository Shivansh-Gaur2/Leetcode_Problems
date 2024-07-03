class Solution {
public:
    int maxArea(vector<int>& height) {
        long long ans = 0;
        int left = 0, right = height.size() - 1;

        while(left <= right){
            long long currHeight = (right - left)*min(height[left], height[right]);
            ans = max(ans, currHeight);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};