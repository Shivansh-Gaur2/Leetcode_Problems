class Solution {
public:
vector<char> vow = {'a', 'e', 'i', 'o' , 'u'};
int helper(int index, int n){
    if(n == 0){
        return 1;
    }
    int cnt = 0; 
    for(int i = index; i < vow.size(); i++){
        cnt += helper(i , n-1);
    }
    return cnt;
}
    int countVowelStrings(int n) {
        return helper(0, n);
    }
};