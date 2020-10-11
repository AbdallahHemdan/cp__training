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

    while (t--) {
        int n, s;
        cin >> n >> s;

        string ret(n, '0');
        int sm = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 9; j >= 0; j--) {
                if (!j && !i) continue;
                if (sm + j * 2 <= s) {
                    ret[i] = '0' + j;
                    ret[n - i - 1] = '0' + j;
                    sm += 2 * j;
                    break;
                }
            }
        }

        // handle odd length numbers
        if (n & 1) {
            if (s - sm <= 9) ret[n / 2] = '0' + (s - sm);
        }

        int checkedSm = 0;
        for (int i = 0; i < n; i++) {
            checkedSm += ret[i] - '0';
        }
        if (checkedSm == s && ret[0] != '0') {
            cout << ret << endl;
        } else {
            cout << -1 << endl;
        }
    }
}