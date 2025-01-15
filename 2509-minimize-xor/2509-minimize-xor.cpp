class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int set = __builtin_popcount(num2);

        int x = 0;

        for(int i = 31; i >= 0; i--){
            if((num1 & (1 << i)) && set > 0){
                x |= (1 << i);
                set--;
            }
        }

        for (int i = 0; i < 32 && set > 0; i++) {
            if (!(x & (1 << i))) { 
                x |= (1 << i);
                set--;
            }
        }

        return x;
    }
};