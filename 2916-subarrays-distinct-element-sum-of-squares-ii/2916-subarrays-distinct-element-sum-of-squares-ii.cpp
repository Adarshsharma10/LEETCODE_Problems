#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    long long sum_tree[400005];
    long long sq_tree[400005];
    long long lazy[400005];
    long long MOD = 1e9 + 7;

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = (l + r) / 2;
            apply(2 * node, l, mid, lazy[node]);
            apply(2 * node + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0;
        }
    }

    void apply(int node, int l, int r, long long val) {
        long long len = (r - l + 1);
        sq_tree[node] = (sq_tree[node] + 2 * val * sum_tree[node] + val * val % MOD * len) % MOD;
        sum_tree[node] = (sum_tree[node] + val * len) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        sum_tree[node] = (sum_tree[2 * node] + sum_tree[2 * node + 1]) % MOD;
        sq_tree[node] = (sq_tree[2 * node] + sq_tree[2 * node + 1]) % MOD;
    }

    long long query_sq(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return sq_tree[node];
        push(node, l, r);
        int mid = (l + r) / 2;
        return (query_sq(2 * node, l, mid, ql, qr) + query_sq(2 * node + 1, mid + 1, r, ql, qr)) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < 4 * n + 5; i++) {
            sum_tree[i] = 0;
            sq_tree[i] = 0;
            lazy[i] = 0;
        }

        unordered_map<int, int> last_seen;
        long long total_ans = 0;

        for (int j = 0; j < n; j++) {
            int last = -1;
            if (last_seen.find(nums[j]) != last_seen.end()) {
                last = last_seen[nums[j]];
            }
            last_seen[nums[j]] = j;

            update(1, 0, n - 1, last + 1, j, 1);

            long long current_sq_sum = query_sq(1, 0, n - 1, 0, j);
            total_ans = (total_ans + current_sq_sum) % MOD;
        }

        return total_ans;
    }
};