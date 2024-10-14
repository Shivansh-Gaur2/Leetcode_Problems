class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;

        long long ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            pq.push(nums[i]);
        }

        while(k--){
            int ele = pq.top();
            ans += ele;
            pq.pop();
            pq.push(ceil((double)ele / 3));
        }

        return ans;
    }
};