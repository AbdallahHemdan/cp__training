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

const int N = 1e5;
ll fact[N + 5];
ll factpow[N + 5];
ll sqr(ll a) { return (a * a) % MOD; }
ll modpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    ll tmp = sqr(modpow(a, b >> 1));
    if (b & 1) tmp = (tmp * a) % MOD;
    return tmp;
}

void init() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= N; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    for (int i = 0; i <= N; ++i) {
        factpow[i] = modpow(fact[i], MOD - 2);
    }
}

ll nCr(int a, int b) {
    return (((fact[a] * factpow[b]) % MOD) * factpow[a - b]) % MOD;
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
    int t;
    cin >> t;
    init();

    while (t--) {
        int a, b;
        cin >> a >> b;

        ll ret = 2 * nCr(a - 1, b);
        ret %= MOD;

        cout << ret << endl;
    }
}