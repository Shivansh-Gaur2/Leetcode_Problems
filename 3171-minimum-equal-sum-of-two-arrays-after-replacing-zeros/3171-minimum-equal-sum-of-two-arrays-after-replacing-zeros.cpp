class Solution {
public:
    long long minSum(vector<int>& a, vector<int>& b) {
        long long ans= 0;
        long long cnta = 0, cntb = 0;
        long long suma = 0, sumb = 0;

        for(int i = 0; i < a.size(); i++){
            suma += a[i];
            if(a[i] == 0) cnta++;
        }

        for(int i = 0; i < b.size(); i++){
            sumb += b[i];
            if(b[i] == 0) cntb++;
        }

        if(cnta > 0 && suma + cnta <= sumb + cntb){
            return sumb+cntb;
        }
        else if(cntb > 0 && sumb + cntb <= suma+ cnta){
            return suma+cnta;
        }

        return suma + cnta == sumb + cntb ? suma : -1;
    }
};