class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> acum(arr.size() + 1, 0);
        
        for(int i = 1; i <= arr.size() ; i++) {
            acum[i] = acum[i - 1] + arr[i - 1];
        }
        
        int ret = 0;
        for(int i = 1; i <= arr.size(); i++){
            for(int j = i; j <= arr.size(); j++) {
                if((j - i + 1) & 1) {
                    ret += acum[j] - acum[i - 1];
                }
            }
        }
        return ret;
    }
};
