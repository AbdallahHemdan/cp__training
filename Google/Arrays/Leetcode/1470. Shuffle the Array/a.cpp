class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int lftIter = 0;
        int rgtIter = n;
        
        vector<int> ret(2 * n);
        for(int i = 0; i < n; i++){
            ret[2 * i] = nums[lftIter++];
            ret[2 * i + 1] = nums[rgtIter++];
        }
        
        return ret;
    }
};
