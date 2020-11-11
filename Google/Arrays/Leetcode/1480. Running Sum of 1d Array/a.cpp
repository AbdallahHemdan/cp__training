class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    vector<int> ret = nums;
    for (int i = 1; i < nums.size(); i++) {
      ret[i] += ret[i - 1];
    }

    return ret;
  }
};
