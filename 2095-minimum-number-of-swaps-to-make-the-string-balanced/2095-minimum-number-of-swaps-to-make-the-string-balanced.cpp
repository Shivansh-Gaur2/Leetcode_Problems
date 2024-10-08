class Solution {
public:
    int minSwaps(string s) {
        int diff = 0;
        int left = 0, right = s.size()-1;
        int swaps = 0;
        while(left < right){
            if(s[left] == '['){
                diff++;
            }
            else if(s[left] == ']'){
                diff--;
            }
            if(diff < 0){
                while(s[right] != '[' && left < right){
                    right--;
                }
                swap(s[left], s[right]);
                right--;
                diff =1;

                swaps++;
            }
            left++;
        }
        return swaps;
    }
};