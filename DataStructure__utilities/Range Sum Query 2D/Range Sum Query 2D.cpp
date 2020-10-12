// https://leetcode.com/articles/range-sum-query-2d-immutable/
const int N = 1010;
const int M = 1010;
int dp[N][M];
int n, m, q;

int getans(int r1, int c1, int r2, int c2) {
    return dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
}

void preprocessing() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> dp[i][j];
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
}

int main() {
    IO;
#ifndef ONLINE_JUDGE
    freopen("In.txt", "r", stdin);
    freopen("Out.txt", "w", stdout);
#else
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
#endif
    cin >> n >> m;
    preprocessing();
    
    cin >> q;
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int sum = getans(r1, c1, r2, c2);
        cout << sum << endl;
    }
}
