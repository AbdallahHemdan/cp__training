class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {  
    const int N = 101;
    int frqA[N], frqB[N];
    
    memset(frqA, 0, sizeof(frqA));
    memset(frqB, 0, sizeof(frqB));
      
    for (size_t i = 0; i < nums.size(); i++) {
        frqA[nums[i]]++;
    }
      
    for (int i = 1; i < N; i++) {
      frqB[i] = frqB[i - 1] + frqA[i - 1];
    }
    
    vector<int> ret(nums.size());
    for (size_t i = 0; i < nums.size(); i++) {
      ret[i] = frqB[nums[i]];
    }

    return ret;
  }
};
