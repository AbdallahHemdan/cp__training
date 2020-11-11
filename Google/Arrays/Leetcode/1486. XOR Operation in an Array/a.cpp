class Solution {
public:
    int xorOperation(int n, int start) {
        int ret = start;
        for(int i = 1; i < n; i++) {
            ret ^= (2 * i + start);
        }
        
        return ret;
    }
};
