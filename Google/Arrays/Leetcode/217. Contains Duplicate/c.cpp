class Solution {
public:
    bool containsDuplicate(vector<int>& a) {
        set<int> st;
        for(int it: a) {
            if(st.count(it)) {
                return true;
            }
            st.insert(it);
        }
        
        return false;
    }
};
