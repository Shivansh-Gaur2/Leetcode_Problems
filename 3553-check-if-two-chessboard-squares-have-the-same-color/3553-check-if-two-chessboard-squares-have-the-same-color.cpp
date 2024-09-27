class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int idxC1 = coordinate1[0] - 'a';
        int idxN1 = coordinate1[1] - '0';
        int idxC2 = coordinate2[0] - 'a';
        int idxN2 = coordinate2[1] - '0';

        cout << idxC1 << " " << idxN1 << " " << idxC2 << " " << idxN2 << endl;
        if((idxC1 + idxN1) %2 ==  (idxC2 + idxN2 ) % 2){
            return true;
        }
        return false;
    }
};