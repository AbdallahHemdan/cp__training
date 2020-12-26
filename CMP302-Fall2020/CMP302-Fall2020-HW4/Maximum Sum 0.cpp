// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>

#define endl '\n'
#define sz size()
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const ll OO = 1e18;
const int oo = INT_MAX;
const double EPS = 1e-9;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }

ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }

double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }

int comp_double(double a, double b) {
  if (fabs(a - b) <= EPS) return 0; // equal
  return (a < b) ? -1 : 1;
}

struct Node {
  int index;
  int rating;
  Node *parent; // this is optional
  vector<Node *> children;
};

int n;
const int N = 1e5 + 5;
ll dp[N][2]; // 0 => parent not taken, 1 => parent taken

ll solve(Node *root, bool isTaken) {
  ll &ret = dp[root->index][isTaken];
  if (~ret) return ret;

  ret = 0;

  ll first = root->rating;
  ll second = 0;
  for (auto i : root->children) {
    first += solve(i, true);
    second += solve(i, false);
  }

  if (isTaken) {
    ret += second;
  } else {
    ret += max(first, second);
  }

  return ret;
}

int main() {
  IO;
  cin >> n;

  vector<Node *> nodes(n);
  for (int i = 0; i < n; i++) {
    nodes[i] = new Node;
    nodes[i]->index = i;
    cin >> nodes[i]->rating;
  }

  int parent, child;
  for (int i = 0; i < n - 1; i++) {
    cin >> parent >> child;
    nodes[child]->parent = nodes[parent];
    nodes[parent]->children.push_back(nodes[child]);
  }

  memset(dp, -1, sizeof(dp));
  cout << solve(nodes[0], false) << endl;

  return 0;
}
