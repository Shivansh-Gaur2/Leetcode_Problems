class Solution {
public:
bool static comp(vector<int>&a , vector<int>& b){
    return a[1] > b[1];
}
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end() , comp);

        int num = 0;
        int temp = truckSize;

        for(int i = 0 ; i < boxTypes.size(); i++){
            if(boxTypes[i][0] <= truckSize){
                num = num + (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            }
            else if(boxTypes[i][0] > truckSize){
                num += (truckSize * boxTypes[i][1]);
                break;
            }
        }
        return num;
    }
};