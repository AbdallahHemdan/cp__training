class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int l = 0, r = 0;
        while(l < n && A[l] < 0) l++;
        r = l;
        l -= 1;
        
        vector<int> ret;
        while(l >= 0 && r < n) {
            int lft = A[l] * A[l];
            int rgt = A[r] * A[r];
            
            if(lft < rgt) {
                ret.push_back(lft);
                l--;
            }else {
                ret.push_back(rgt);
                r++;
            }
        }
        
        while(l >= 0) {
            ret.push_back(A[l] * A[l]);
            l--;
        }
        
        while(r < n) {
            ret.push_back(A[r] * A[r]);
            r++;
        }
        
        return ret;
    }
};
