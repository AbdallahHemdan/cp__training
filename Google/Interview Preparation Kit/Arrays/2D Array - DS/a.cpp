// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int ret = INT_MIN;
    for(int i=0; i< 4; i++) {
        for(int j=0; j<4; j++) {
            int curHour = 0;
            
            for(int k=j; k<j+3;k++) {
                curHour += arr[i][k];
                curHour += arr[i + 2][k];
            }

            curHour += arr[i+1][j+1];
            ret = max(ret, curHour);
        }
    }
    
    return ret;
}
