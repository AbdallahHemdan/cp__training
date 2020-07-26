/*Author : Abdallah Hemdan */ 
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
#include<array>
#include<tuple>
#include <utility>
#include <functional>
#include <locale>
#define     all(v)            v.begin(),v.end()
#define     mp                     make_pair
#define     pb                     push_back
typedef   long long int               ll ;
 
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
 
using namespace std ;
int main(){
    int a1,a2,a3,a4 ; 
    cin >> a1 >> a2 >> a3 >> a4 ; 
    int cnt_1 = 0 ,cnt_2 = 0 ,cnt_3 = 0 ,cnt_4 = 0 ;  
    string s ; 
    cin >> s ;
    for(int i=0 ;i<s.size() ; i++)
        if(s[i]=='1')
            cnt_1++ ; 
        else if (s[i]=='2')
            cnt_2++ ; 
        else if (s[i]=='3')
            cnt_3++ ; 
        else
            cnt_4++ ; 
    cout << (cnt_1*a1+cnt_2*a2+cnt_3*a3+cnt_4*a4) << endl ;
}
    
 