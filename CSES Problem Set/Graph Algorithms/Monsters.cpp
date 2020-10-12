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

using cell = pair<int, int>;

int n, m;
const int N = 1e3 + 13;
char g[N][N];
int dis[N][N];
int dist[N][N];

cell par[N][N];

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && g[i][j] != '#');
}

string getDirection(cell a, cell b) {
    // b : parent
    if (a.first > b.first) return "D";
    if (a.first < b.first) return "U";
    if (a.second > b.second) return "R";
    if (a.second < b.second) return "L";
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
    cell s;
    vector<cell> mon;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') {
                s = {i, j};
            }
            if (g[i][j] == 'M') {
                mon.emplace_back(i, j);
            }
        }
    }

    // for monoster
    memset(dis, -1, sizeof(dis));
    queue<cell> q;
    for (auto it : mon) {
        q.push(it);
        dis[it.first][it.second] = 0;
    }

    while (!q.empty()) {
        cell u = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = u.first + dx[k];
            int ny = u.second + dy[k];

            if (valid(nx, ny) && dis[nx][ny] == -1) {
                dis[nx][ny] = dis[u.first][u.second] + 1;
                q.push({nx, ny});
            }
        }
    }

    memset(par, -1, sizeof(par));
    memset(dist, -1, sizeof(dist));
    while (q.size()) q.pop();
    dist[s.first][s.second] = 0;

    q.push(s);

    while (q.size()) {
        cell u = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = u.first + dx[k];
            int ny = u.second + dy[k];

            if (valid(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[u.first][u.second] + 1;
                par[nx][ny] = u;
                q.push({nx, ny});
            }
        }
    }
    cell tar = {-1, -1};
    for (int j = 0; j < m; j++) {
        if (g[0][j] == '.' && (dist[0][j] < dis[0][j] || dis[0][j] == -1)) {
            tar = {0, j};
            break;
        }
        if (g[n - 1][j] == '.' &&
            (dist[n - 1][j] < dis[n - 1][j] || dis[n - 1][j] == -1)) {
            tar = {n - 1, j};
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (g[i][0] == '.' && (dist[i][0] < dis[i][0] || dis[i][0] == -1)) {
            tar = {i, 0};
            break;
        }
        if (g[i][m - 1] == '.' &&
            (dist[i][m - 1] < dis[i][m - 1] || dis[i][m - 1] == -1)) {
            tar = {i, m - 1};
            break;
        }
    }

    if (s.first == 0 || s.first == n - 1 || s.second == 0 ||
        s.second == m - 1) {
        cout << "YES" << endl;
        return cout << 0 << endl, 0;
    }
    if (tar.first != -1) {
        cout << "YES" << endl;

        cell e = tar;
        vector<cell> path;
        while (e.first != -1 && e.second != -1) {
            path.push_back(e);
            e = par[e.first][e.second];
        }

        cout << path.size() - 1 << endl;
        string ret;
        for (int i = path.sz - 2; i >= 0; --i) {
            cell a = path[i];
            cell b = path[i + 1];
            ret += getDirection(a, b);
        }
        cout << ret << endl;
    } else {
        cout << "NO" << endl;
    }
}