class Solution {
public:
    int passThePillow(int n, int time) {
        int pos = 1;
        bool flag = true;
        while(time--){
            if(flag){
                pos++;
                if(pos == n){
                    flag = !flag;
                }
            }
            else{
                pos--;
                if(pos ==1){
                    flag = !flag;
                }
            }
        }
        return pos;
    }
};