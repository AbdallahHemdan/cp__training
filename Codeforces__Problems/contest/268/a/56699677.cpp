/*Author : Abdallah Hemdan */
/***********************************************/
/* Dear online judge:
* I've read the problem, and tried to solve it.
* Even if you don't accept my solution, you should respect my effort.
* I hope my code compiles and gets accepted.
*  ___  __
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
#define     all(v)            v.begin(),v.end()
#define     mp                     make_pair
#define     pb                     push_back
#define     endl                     '\n'
 
typedef   long long int               ll;
 
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
 
using namespace std;
int main() {
	int n; 
	cin >> n; 
	map<int, int> a;
	map<int, int> b;
	int t1, t2; 
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2; 
		a[t1]++;
		b[t2]++;
	}
	map<int, int> ::iterator it;
	int res = 0;
	for (it = a.begin(); it != a.end(); it++) {
		res += it->second * b[it->first];
	}	
	cout << res << endl;
}