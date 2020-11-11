class Solution {
private: 
    int getNumberOfDigits(int n) {
        int cnt = 0;
        while(n) {
            cnt++;
            n /= 10;
        }
        
        return cnt; 
    }
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(getNumberOfDigits(nums[i]) % 2 == 0) ret++;
        }
        return ret;
    }
};
