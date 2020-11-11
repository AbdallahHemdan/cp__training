class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> frq;
    vector<int> ret = {-1, -1};

    for (int i = 0; i < nums.size(); i++) {
      frq[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      if (frq[complement] && frq[complement] != i) {
        ret = {i, frq[complement]};
      }
    }

    return ret;
  }
};
