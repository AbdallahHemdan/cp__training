const double EPS = 1e-9;

// function to get (b ^ e)
ll fastpow(ll b, ll e) {
  if (!e)
    return 1;
  if (e & 1)
    return b * fastpow(b, e - 1);
  ll x = fastpow(b, e / 2);
  return x * x;
}

// function to get (b ^ e % MOD)
ll PowMod(ll bs, ll ex, ll M) {
  if (!ex)
    return 1;
  ll p = PowMod((bs * bs) % M, ex >> 1, M);
  return (ex & 1) ? (p * bs) % M : p;
}

// function to compare two double number to avoid percision errors
int comp_double(double a, double b) {
  if(fabs(a - b) <= EPS) {
     return 0; // equal
  }
  return (a < b) ? -1 : 1; 
}
