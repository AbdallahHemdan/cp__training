vector<vector<int>> rotateImage(vector<vector<int>> a) {
    int n = a.size();
    
    // 1st. Transpose
    for(int i = 0 ; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(a[i][j], a[j][i]);      
        }
    }
    
    // 2nd. Flipping
    for(int i=0; i<n; i++) {
        for(int j = 0; j < n / 2; j++) {
            swap(a[i][j], a[i][n-j-1]);
        }
    }
    return a;
}
