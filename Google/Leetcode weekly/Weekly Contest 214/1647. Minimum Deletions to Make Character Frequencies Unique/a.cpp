class Solution {
public:
    int minDeletions(string s) {
        int frq[26] = {0};
        for(char c: s) {
            frq[c - 'a']++;
        }
        
        int ret = 0;
        set<int> st;
        for(int i = 0; i < 26; i++) {
            int x = frq[i];
            while(st.count(x) && x > 0) {
                ret++;
                x--;
            }
            st.insert(x);
        }
        return ret;
    }
};
