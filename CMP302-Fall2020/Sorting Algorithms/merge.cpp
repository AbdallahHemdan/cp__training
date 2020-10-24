/**
 * Merge sort: keeps dividing the array into 2 halves till reach lowest level
 * keep merging the 2 halves till combine them in one sorted array
 * */

/**
 * Auxiliary Space: Θ(𝑛)
 * Complexity: Θ(𝑛log𝑛)
 * Stable: true
 * Recurrence relation: T(n) = 2T(n/2) + θ(n)
 * Approach: Divide and Conquer
 * Takes linear time to merge the 2 halves
 * */

void merge(vector<int> &a, int l, int m, int r) {
    int lftSz = m - l + 1;
    int rgtSz = r - m;

    vector<int> L(lftSz);
    vector<int> R(rgtSz);

    for (int i = 0; i < lftSz; i++) {
        L[i] = a[l + i];
    }
    for (int j = 0; j < rgtSz; j++) {
        R[j] = a[m + 1 + j];
    }

    int k = l;
    int lft = 0;
    int rgt = 0;

    while (lft < lftSz && rgt < rgtSz) {
        if (L[lft] <= R[rgt]) {
            a[k] = L[lft++];
        } else {
            a[k] = R[rgt++];
        }
        k++;
    }

    while (lft < lftSz) {
        a[k] = L[lft++];
        k++;
    }
    while (rgt < rgtSz) {
        a[k] = R[rgt++];
        k++;
    }
}

void mergeSort(vector<int> &a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

void MergeSort(vector<int> &a) {
    int n = a.size() - 1;
    mergeSort(a, 0, n);
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i :a) cin >> i;

    MergeSort(a);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n];
    }
}
