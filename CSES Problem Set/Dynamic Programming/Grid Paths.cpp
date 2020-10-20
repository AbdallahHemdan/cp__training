// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int oo = INT_MAX;
const ll OO = 1e18;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }

ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }

double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }

int comp_double(double a, double b) {
    if (fabs(a - b) <= EPS) return 0; // equal
    return (a < b) ? -1 : 1;
}

int n;
const int N = 1001;
char g[N][N];
int dp[N][N];

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n && g[i][j] != '*');
}

int solve(int i, int j) {
    if (i == n - 1 && j == n - 1) {
        return 1;
    }
    int &ret = dp[i][j];
    if (~ret) return ret;
    ret = 0;
    if (valid(i + 1, j)) {
        ret = (ret % MOD + solve(i + 1, j) % MOD) % MOD;
    }
    if (valid(i, j + 1)) {
        ret = (ret % MOD + solve(i, j + 1) % MOD) % MOD;
    }

    return ret;
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
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    if (g[0][0] == '*' || g[n - 1][n - 1] == '*') {
        cout << 0 << endl;
    } else {
        cout << solve(0, 0) << endl;
    }
}
