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
#define		  mp							make_pair
#define		  pb					     	push_back
#define		 endl			                  '\n'
#define       sz							  ((int)(size()))
#define       len							 length()
#define       IO 			ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define       X 							  first 
#define 	  Y 							 second
#define     all(v)	      			((v).begin()), ((v).end())
#define    rall(v)                  ((v).rbegin()), ((v).rend())
#define	  lop(i,init,n)		     	 for(int i=init;i<n;++i)
#define     Even(Num) 						Num % 2 == 0
#define   mms(Arr,Value)           memset(Arr,Value,sizeof(Arr))
#define   SetPre(Ans,num)	     fixed << setprecision(num) << (Ans)
#define     vi                           vector<int>
#define     vll                          vector<ll>
#define     si                            set<int>
#define     sll                           set<ll>
typedef   long long int                     ll;
typedef   long double                       ld;


const double EPS = 1e-9;
const int MOD = 1e9 + 7;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

//ll GCD(ll a, ll b) {
//	if (b == 0) return a;
//	return GCD(b, a%b);
//}

//ll LCM(ll a, ll b) {
//	return a / (GCD(a, b))* b;
//}

const int dx[] = { 1,-1,0,0,0,0 };
const int dy[] = { 0,0,1,-1,0,0 };
const int dz[] = { 0,0,0,0,1,-1 };

using namespace std;

int main() {
	IO;
	ll n;
	cin >> n;
	map <ll,ll> Freq;
	ll x;
	lop(i, 0, n) {
		cin >> x;
		Freq[x] = i + 1;
	}

	ll m;
	cin >> m;

	ll Sum1 = 0, Sum2 = 0;
	while (m--) {
		cin >> x;
		Sum1 += (ll)Freq[x];
		Sum2 += n - (ll)Freq[x] + 1;
	}
	cout << Sum1 << " " << Sum2 << endl;

}