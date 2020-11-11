// Solution:
/**
 * Just swap each 2 element (1, n), (2, n-1), ...etc
 */
class Solution {
   public:
    void reverseString(vector<char>& a) {
        int n = a.size();
        for (int i = 0; i < n / 2; i++) {
            swap(a[i], a[n - i - 1]);
        }
    }
};