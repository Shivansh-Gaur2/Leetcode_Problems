class SmallestInfiniteSet {
    set<int>st;
public:
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)st.insert(i);
    }
    
    int popSmallest() {
        int it = *begin(st);
        st.erase(it);
        return it;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};