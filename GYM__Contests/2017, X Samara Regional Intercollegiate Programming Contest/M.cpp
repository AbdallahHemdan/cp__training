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

int main() {
    IO;
#ifndef ONLINE_JUDGE
    freopen("In.txt", "r", stdin);
    freopen("Out.txt", "w", stdout);
#else
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
#endif
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);

    int sm = 0;
    int ok = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;

        sm += a[i].first;
        if (!a[i].first) ok = 1;
    }
    if (sm < n && ok) {
        cout << "YES" << endl;

        sort(all(a));
        int l = 0, r = 0;

        while (l < n && !a[l].first) l++;
        while (l < n) {
            for (int i = 0; i < a[l].first; i++) {
                cout << a[l].second + 1 << ' ' << a[r++].second + 1 << endl;
            }
            l++;
        }
    } else {
        cout << "NO" << endl;
    }

}
