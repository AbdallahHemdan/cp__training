// Author : Abdalah Hemdan
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

const int N = 22;
struct house {
    int r, g, b;
};

int n;
house a[N];
int dp[N][4];

int solve(int idx, int lst) {
    if (idx == n) {
        return 0;
    }

    int &ret = dp[idx][lst];
    if (~ret) return ret;
    ret = INT_MAX;
    if (lst != 0) {
        ret = min(ret, a[idx].r + solve(idx + 1, 0));
    }
    if (lst != 1) {
        ret = min(ret, a[idx].g + solve(idx + 1, 1));
    }
    if (lst != 2) {
        ret = min(ret, a[idx].b + solve(idx + 1, 2));
    }

    return ret;
}

int estimateCost(const vector<string> &streets) {
    n = streets.size();
    for (int i = 0; i < n; i++) {
        istringstream iss(streets[i]);
        iss >> a[i].r >> a[i].g >> a[i].b;
    }

    // 0 -> red
    // 1 -> green
    // 2 -> blue
    memset(dp, -1, sizeof(dp));
    return solve(0, 3);
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
    cin.ignore();
    vector<string> streets(n);
    for (auto &i : streets) {
        getline(cin, i);
    }
    cout << estimateCost(streets) << endl;
}
