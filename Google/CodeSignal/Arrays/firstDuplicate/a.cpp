int firstDuplicate(vector<int> a) {
    int n = a.size();
    set<int> st;
    
    int ret = -1;
    for(int i = 0; i < n; i++) {
        if(st.count(a[i])) {
            ret = a[i];
            break;    
        } else {
            st.insert(a[i]);
        }
    }
    
    return ret;
}
