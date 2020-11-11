class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int l = 0, r = n - 1;
        
        vector<int> res;
        while(l <= r) {
            int lft = A[l] * A[l];
            int rgt = A[r] * A[r];
            
            if(rgt > lft) {
                res.push_back(rgt);
                r--;
            }else{
                res.push_back(lft);
                l++;
            }
        }
        
        for(int i = 0; i < n / 2 ; i++) {
            swap(res[i], res[n - i - 1]);
        }
        return res;
    }
};
