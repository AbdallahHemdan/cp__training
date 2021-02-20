#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define in insert
#define f first
#define s second

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << n / 5 + (n % 5 != 0) << endl;
  }
}
