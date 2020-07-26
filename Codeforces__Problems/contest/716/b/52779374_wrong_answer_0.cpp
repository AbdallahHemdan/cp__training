/*Author : Abdallah Hemdan */
/**************************/
/*Dear online judge:
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
#define		  x								 first
#define		  y								 second
#define       sz							  size()
#define       len							 length()
#define       IO 			ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

int freq[26]; 
int main() {
	IO;
	string s;  
	cin >> s; 

	if (s.sz < 26) {
		return cout << -1 << endl, 0; 
	}

	bool Check = false; 
	lop(i, 0, s.sz - 26 + 1) {
		mms(freq, 0);
		int QCnt = 0; 
		lop(j, i, i + 26) {
			if (s[j] != '?') {
				freq[s[j] - 'A']++; 
			}
			else {
				QCnt++; 
			}
		}

		bool flag = true;
		int Cnt = 0; 
		lop(k, 0, 26) {
			if (freq[k] > 1) {
				flag = false;
				break; 
			}
			if (freq[k] == 0) {
				Cnt++; 
			}
		}

		if (!flag || Cnt != QCnt) {
			continue; 
		}
		int ind = 0; 
		lop(j, i, i + 25) {
			if (s[j] == '?') {
				lop(h, ind, 26) {
					if (freq[h] == 0) {
						s[j] = char(h + 'A'); 
						freq[h] = 1;
						ind = h; 
						break; 
					}
				}
			}
		}
		Check = true; 
		break;
	}
	if (Check) {
		lop(i, 0, s.sz) {
			if (s[i] == '?') {
				s[i] = 'A'; 
			}
		}
		cout << s << endl;
	}
	else {
		cout << -1 << endl;
	}
}