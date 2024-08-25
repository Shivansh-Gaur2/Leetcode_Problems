class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
       int n = arr.size();
       vector<int> prefix(n+1, 0);
       for(int i = 1 ; i <= n; i++){
        prefix[i] = prefix[i-1] + arr[i-1];
       } 

       int sum = 0;
       for(int i = 0; i < n; i++){
        for(int j = i; j < n; j+=2){
            sum += prefix[j+1]- prefix[i];
        }
       }
       return sum;
    }
};