vector<vector<int>> rotateImage(vector<vector<int>> a) {
    int n = a.size();
    vector<vector<int>> b(n, vector<int>(n));
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int nx = j;
            int ny = n - i - 1;
            b[nx][ny] = a[i][j];
        }
    }
    
    return b;
}
