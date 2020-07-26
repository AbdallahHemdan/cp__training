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
    int n ; 
    cin >> n ; 
    int s_score = 0 , d_score = 0 ; 
    int arr[n] ; 
    for(int i=0 ;i<n ; i++)
        cin >> arr[i] ;
    int ptr1 = 0 ,ptr2 = n-1 ; 
    while(ptr1<ptr2){
        if(arr[ptr1]>=arr[ptr2]){
            s_score+=arr[ptr1] ; 
            ptr1++ ; 
        }
        else if (arr[ptr1]<arr[ptr2]){
            s_score+=arr[ptr2] ; 
            ptr2-- ;
        }
        if(arr[ptr1]>=arr[ptr2]){
            d_score+=arr[ptr1] ; 
            ptr1++ ; 
        }
        else if (arr[ptr1]<arr[ptr2]){
            d_score+=arr[ptr2] ; 
            ptr2-- ;
        }
    }
    if(ptr1==ptr2)
        s_score+=arr[ptr1] ; 
    cout << s_score << " " << d_score << endl ;
    
        
}