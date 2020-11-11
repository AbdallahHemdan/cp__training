class Solution {
private:
    static const int N = 1e5 + 15;
    int BIT[N] = {0};
    
    void update(int x) {
        while(x < N) {
            BIT[x]++;
            x += (x&-x);
        }
    }
    
    int get(int x) {
        int ret = 0;
        while(x > 0) {
            ret += BIT[x];
            x -= (x&-x);
        }
        return ret;
    }
public:
    int createSortedArray(vector<int> &a) {
        int n = a.size();
        
        int ret = 0;
        const int MOD = 1e9 + 7;
        for(int i = 0; i < n ; i++) {
            int l = get(a[i] - 1);
            int r = i - get(a[i]);
            
            ret += min(l, r);
            ret %= MOD;
            
            update(a[i]);
        }    
        cout << ret << endl;
        return ret;
    }
};
