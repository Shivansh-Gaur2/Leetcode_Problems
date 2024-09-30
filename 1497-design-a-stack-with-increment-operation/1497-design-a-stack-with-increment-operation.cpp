class CustomStack {
public:
    vector<int> st;
    int curr;
    int size;

    CustomStack(int maxSize) {
        st = vector<int>(maxSize, -1);
        curr = maxSize - 1;
        size = maxSize;
    }
    
    void push(int x) {
        if(curr == -1) {
            return;
        }
        st[curr] = x;
        curr--;
    }
    
    int pop() {
        if(curr == size - 1) {
            return -1;
        }
        curr++;
        int num = st[curr];
        st[curr] = -1;
        return num;
    }
    
    void increment(int k, int val) {
        int idx = size - 1;
        int limit = min(k, size - curr - 1);

        while(limit--) {
            if(st[idx] == -1) {
                break;
            }
            st[idx] += val;
            idx--;
        }
    }
};
