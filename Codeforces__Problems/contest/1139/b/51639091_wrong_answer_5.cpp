/*Author : Abdallah Hemdan */
/**************************/
/* Dear online judge:
* I've read the problem, and tried to solve it.
* Even if you don't accept my solution, you should respect my effort.
* I hope my code compiles and gets accepted.
*  ___   __
* |\  \|\  \
* \ \  \_\  \
*  \ \   ___ \emdan
*   \ \  \\ \ \
*    \ \__\\ \_\
*     \|__| \|__|
*/
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <numeric>
#include <array>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <functional>
#include <locale>
#define mp make_pair
#define pb push_back
#define endl '\n'
#define sz size()
#define len length()
#define IO                 \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define X first
#define Y second
#define all(v) ((v).begin()), ((v).end())
#define lop(i, init, n) for (int i = init; i < n; ++i)
#define mms(Arr, Value) memset(Arr, Value, sizeof(Arr))
#define SetPre(Ans, num) fixed << setprecision(num) << (Ans)
typedef long long int ll;
typedef long double ld;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);

// ll GCD(ll a, ll b) {
//	if (b == 0) return a;
//	return GCD(b, a%b);
//}
// ll LCM(ll a, ll b) {
//	return a / (GCD(a, b))* b;
//}

const int dx[] = { 1, -1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, 1, -1, 0, 0 };
const int dz[] = { 0, 0, 0, 0, 1, -1 };

using namespace std;

int n;
ll Ansi;
ll Last;

int main() {
	IO;

	cin >> n;
	vector<ll> Arri(n);

	lop(i, 0, n)
		cin >> Arri[i];

	Ansi = Arri[n - 1],Last = Arri[n - 1];
	if (n == 1) Last = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (Last > Arri[i]) {
			Ansi += Arri[i];
			Last = Arri[i];
		}

		else if (Arri[i] - 1 > 0) {
			if (Arri[i] <= Ansi) {
				Ansi += Last - 1;
				Last--;
				
			}
			else {
				Ansi = Arri[i];
				Last = Arri[i];
			}
		}
	}
	cout << Ansi << endl;
	return 0;
}