const double EPS = 1e-9;

// [1, 2]
ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b))*b; }

// [3]
ll fastpow(ll b, ll e) {
  if (!e)
    return 1;
  if (e & 1)
    return b * fastpow(b, e - 1);
  ll x = fastpow(b, e / 2);
  return x * x;
}

// [4]
ll PowMod(ll bs, ll ex, ll M) {
  if (!ex)
    return 1;
  ll p = PowMod((bs * bs) % M, ex >> 1, M);
  return (ex & 1) ? (p * bs) % M : p;
}

// [5]
int comp_double(double a, double b) {
  if(fabs(a - b) <= EPS) {
     return 0; // equal
  }
  return (a < b) ? -1 : 1; 
}
