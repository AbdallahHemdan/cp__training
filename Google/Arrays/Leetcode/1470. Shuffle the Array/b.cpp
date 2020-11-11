class Solution {
public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ret(2*n);
    for(int i = 0; i < n ; i++){
      ret[2 * i] = nums[i];
      ret[2 * i + 1] = nums[n + i];
    }

    return ret;
  }
};
