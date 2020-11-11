class Solution {
   private:
    void solve(int lft, int rgt, vector<char>& a) {
        if (rgt <= lft) return;  // base condition
        char lftChar = a[lft];
        char rgtChar = a[rgt];

        a[lft++] = rgtChar;
        a[rgt--] = lftChar;
        solve(lft, rgt, a);
    }

   public:
    void reverseString(vector<char>& a) {
        int n = a.size() - 1;
        solve(0, n, a);
    }
};