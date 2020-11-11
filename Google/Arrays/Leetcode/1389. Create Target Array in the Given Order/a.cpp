class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int aSize = nums.size();
        vector<int> target(aSize);
        
        for(int i = 0; i < aSize; i++){
            int val = nums[i];
            int idx = index[i];
            
            for(int j = aSize - 1; j >= idx; j--){
                if(j - 1 >= 0) {
                    target[j] = target[j - 1];
                }
            }
            target[idx] = val;
        }
        return target;
    }
};
