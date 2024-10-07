class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int gc = gcd(x,y);
        if(x+y < target) return false;
        if(target % gc == 0) return true;
        return false;
    }
};