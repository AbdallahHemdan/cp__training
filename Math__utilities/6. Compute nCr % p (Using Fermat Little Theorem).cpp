// SRC: https://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/

const int MOD = 1e9 + 7;
const int N = 1e5;
ll fact[N + 5];
ll factInv[N + 5];
ll sqr(ll a) { return (a * a) % MOD; }
ll modpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    ll tmp = sqr(modpow(a, b >> 1));
    if (b & 1) tmp = (tmp * a) % MOD;
    return tmp;
}

void init() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= N; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    for (int i = 0; i <= N; ++i) {
        factInv[i] = modpow(fact[i], MOD - 2);
    }
}

ll nCr(int a, int b) {
    return (((fact[a] * factInv[b]) % MOD) * factInv[a - b]) % MOD;
}
