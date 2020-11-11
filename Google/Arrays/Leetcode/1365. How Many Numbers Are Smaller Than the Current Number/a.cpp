class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> ret;
    int aSize = nums.size();
    for (int i = 0; i < aSize; i++) {
      int mnCnt = 0;
      for (int j = 0; j < aSize; j++) {
        if (i != j && nums[i] > nums[j]) {
          mnCnt++;
        }
      }
      ret.push_back(mnCnt);
    }
    return ret;
  }
};
