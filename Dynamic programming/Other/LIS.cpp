const int N = 1010;
int n, a[N];

/**
 * Computes the length of the longest increasing subsequence (LIS) of
 * the global array "a" in time complexity of O(n.log(n)).
 *
 * @return the length of the LIS of array "a".
 */
int getLIS() {
    int len = 0;
    vector<int> LIS(n, INT_MAX);

    for (int i = 0; i < n; ++i) {
        // To get the length of the longest non decreasing subsequence (a[i] <= a[j])
        // replace function "lower_bound" with "upper_bound"
        int idx = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
        LIS[idx] = a[i];
        len = max(len, idx);
    }

    return len + 1;
}

int main() {
    IO;
#ifndef ONLINE_JUDGE
    freopen("In.txt", "r", stdin);
    freopen("Out.txt", "w", stdout);
#else
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << getLIS() << endl;
}
