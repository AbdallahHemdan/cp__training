class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> ret(n);
        
        for(int i = 0; i < n; i ++) {
            ret[i] = A[i] * A[i];
        }
        
        sort(ret.begin(), ret.end());
        return ret;
    }
};
