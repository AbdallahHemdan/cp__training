// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define IO                                                             \
    ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0), \
        cout.tie(0)
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
double distance(double x1, double y1, double x2, double y2) {
    return hypot(fabs(x1 - x2), fabs(y1 - y2));
}
int comp_double(double a, double b) {
    if (fabs(a - b) <= EPS) return 0;  // equal
    return (a < b) ? -1 : 1;
}

const int N = 2e5 + 25;
ll n, ret;
vi adj[N];
ll dp[N][3];

void solve(int u, int par) {
    dp[u][0] = dp[u][1] = 0;
    int ok = 0;

    for (auto v : adj[u]) {
        if (v != par) {
            ok = 1;
            solve(v, u);
        }
    }

    if (!ok) return;

    for (auto v : adj[u]) {
        if (v != par) {
            dp[u][0] += max(dp[v][0], dp[v][1]);
        }
    }

    // ! dp[src][0] = Sum of all children res
    for (auto v : adj[u]) {
        if (v != par) {
            dp[u][1] = max(dp[u][1],
                           dp[v][0] + 1 + (dp[u][0] - max(dp[v][0], dp[v][1])));
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
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(1, -1);

    cout << max(dp[1][1], dp[1][0]) << endl;
}