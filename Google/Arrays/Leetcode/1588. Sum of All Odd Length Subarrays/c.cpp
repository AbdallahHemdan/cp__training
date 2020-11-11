class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ret = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int totalOccur = (i + 1) * (n - i);
            int oddOcc = (totalOccur + 1) / 2;
            ret += (oddOcc * arr[i]);
        }
        
        return ret;
    }
};
