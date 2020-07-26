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
    string s ; 
    cin >> s; 
    int ans = 0 ,temp; 
    for(int i=0 ;i<s.size()-1;i++){
        temp = abs(s[i]-s[i+1]) ; 
        if(temp<=13)
            ans+=temp ; 
        else 
            ans+=(26-temp) ; 
    }
    // Walk of The 1st element..As we started from a..
    if((s[0]-'a') <= 13)
        cout << ans+(s[0]-'a')<< endl ;
    else
        cout << ans+(26-(s[0]-'a')) << endl ;
 }