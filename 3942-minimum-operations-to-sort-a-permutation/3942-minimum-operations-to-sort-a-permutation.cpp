class Solution {
public:
    int minOperations(vector<int>& A) {
        int n = A.size();
        int asc = 1, dsc = 1;

        for (int i = 1; i < n; i++) {
            if (A[i] == (A[i - 1] + 1) % n)
                asc++;

            if (A[i - 1] == (A[i] + 1) % n)
                dsc++;
        }

        if (asc == n) {
            if (A[0] == 0) return 0;
            return min(n - A[0], A[0] + 2);
        }

        if (dsc == n)
            return min(n - A[n - 1], A[n - 1]) + 1;

        return -1;
    }
};