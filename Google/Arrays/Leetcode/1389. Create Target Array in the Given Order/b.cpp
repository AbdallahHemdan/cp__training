class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int aSize = nums.size();
        vector<int> target;
        for(int i = 0; i < aSize; i++){
            int idx = index[i];
            int val = nums[i];
            
            target.insert(target.begin() + idx, val);
        }
        return target;
    }
};
