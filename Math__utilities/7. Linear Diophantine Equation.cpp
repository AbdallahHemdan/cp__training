#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

// Getting a solution 
ll eGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = eGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// a.x + b.y = c
bool solveLDE(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = eGCD(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}


// Getting all solutions
/**
* after getting the first solution, you can get all solutions using Bézout's identity
* x = x0 + k * (b/g)
* y = y0 - k * (a/g)
*/
