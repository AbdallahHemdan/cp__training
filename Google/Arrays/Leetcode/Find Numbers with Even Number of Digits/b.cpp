class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < nums.size(); i++) {
            int noOfDigits = 1 + floor(log10(nums[i]));
            if(noOfDigits % 2 == 0) {
                ret++;
            }
        }
        return ret;
    }
};
