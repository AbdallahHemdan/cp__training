class Solution {
public:
    bool containsDuplicate(vector<int>& a) {
        int n = a.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(a[i] == a[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
