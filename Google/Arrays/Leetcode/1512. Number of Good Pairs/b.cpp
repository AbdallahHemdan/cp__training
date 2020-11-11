class Solution {
public:
    int numIdenticalPairs(vector<int> &nums) {
      int numsSize = nums.size();
      int noOfGoodPairs = 0;

      unordered_map<int, int> frq;
      for (int i = 0; i < numsSize; i++) {
        noOfGoodPairs += frq[nums[i]];
        frq[nums[i]]++;
      }
      return noOfGoodPairs;
    }
};
