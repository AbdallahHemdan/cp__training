class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = -1, cnt = 0;
        int mxOnes = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                cnt++;
                l = i;
            }else {
                if(l != -1) {
                    mxOnes = max(mxOnes, cnt);
                    l = -1, cnt = 0;
                }
            }
        }
        
        mxOnes = max(mxOnes, cnt);
        return mxOnes;
    }
};
