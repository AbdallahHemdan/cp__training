class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    int mxCandies = INT_MIN;
    for (int candy : candies) {
      mxCandies = max(mxCandies, candy);
    }

    vector<bool> ret(candies.size());
    for (int i = 0; i < candies.size(); i++) {
      ret[i] = (candies[i] + extraCandies >= mxCandies);
    }

    return ret;
  }
};
