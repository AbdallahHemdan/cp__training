int firstDuplicate(vector<int> a) {
    int n = a.size();
    for(int i=0; i<n; i++) {
        int pos = abs(a[i]) - 1;
        if(a[pos] < 0) {
            return pos + 1;
        } else{
            a[pos] = -a[pos];
        }
    }
    
    return -1;
}
