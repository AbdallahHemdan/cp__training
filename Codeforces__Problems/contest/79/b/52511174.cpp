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
#include <utility>
#include <functional>
#include <locale>
#define     all(v)            v.begin(),v.end()
#define     mp                     make_pair
#define     pb                     push_back
#define     endl                     '\n'

typedef   long long int               ll ;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
using namespace std;

const int MN = 1e4+5;
int n, m, k, t, i, x, y, arr[MN];

int main(){
	cin >> n >> m >> k >> t;
	for(i=1;i<=k;i++){
		cin >> x >> y ; 
		arr[i]=x*m+y;
	}
	sort(arr+1,arr+k+1);
	for(i=1;i<=t;i++){
		cin >> x >> y ; 
		int p=lower_bound(arr+1,arr+k+1,x*m+y)-arr;
		if(x*m+y==arr[p]) cout << "Waste" << endl ;
		else{
			int s=((x-1)*m+y-p+1)%3;
			printf("%s\n",(s==1)?"Carrots":(s==2)?"Kiwis":"Grapes");
		}
	}
	return 0;
}