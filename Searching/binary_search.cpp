#include <bits/stdc++.h>
using namespace std;
using ld = long double;

bool ok(int m) {
  // TODO: to be implemented
}

/**
 * * Conditions
 * The function must be a monotonic function matching the binary search type
 * (min or max).
 *
 * In binary search for answer, some times the value of r is not clear
 * So we have a small trick to get a tight value for r
 *
 *
 *
 * * Trick for value of r
 * ll r = 1;
 * while(!ok(r)) r <<= 1;
 *
 *
 * * Binary Search on doubles
 * Instead of using while loop with accurrecy of EPS which is sometimes fail
 * You can use fixed number of iterations which is at max 100 iteration
 *
 * In case you got TLE in the binary search, try to decrease the number of
 * iterations
 *
 * In binary search on double in case of the m is ok
 * you can't increase the value of l or r by mid + 1 | mid - 1 as it's a
 * double values instead of that set (l = mid) or (r = mid)
 */

int binarySearch() {
  int ret;
  int l = 0, r = 1e9;
  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (ok(mid)) {
    } else {
    }
  }
}

int binarySearch_double() {
  ld ret = -1;
  ld l = 0, r = 1e8;

  for (int i = 0; i < 100; ++i) {
    ld mid = l + (r - l) / 2.0;

    if (ok(mid)) {
      // l = mid
    } else {
      // r = mid
    }
  }
}
