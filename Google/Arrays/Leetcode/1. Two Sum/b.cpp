class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> frq;
    vector<int> ret = {-1, -1};

    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];

      if (frq.count(complement)) {
        ret = {i, frq[complement]};
      }

      frq[nums[i]] = i;
    }

    return ret;
  }
};
