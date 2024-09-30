class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int opt1=0,opt2=0;
        int i=1;
        int r=red,b=blue;
        while(true)
        {
            if(r-i>=0)
            {
                r-=i;
                opt1++;
            }
            else break;
            i++;
            if(b-i>=0)
            {
                b-=i;
                opt1++;
            }
            else break;
            i++;
        } 
        i=1;
        while(true)
        {
            if(blue-i>=0)
            {
                blue-=i;
                opt2++;
                cout<<i<<" ";
            }
            else break;
            i++;
            if(red-i>=0)
            {
                red-=i;
                opt2++;
            }
            else break;
            i++;
        }  
        if(opt1<opt2)cout<<"opt2";
        return max(opt1,opt2);
    }
};