class Solution {
public:
    vector<vector<int>> adj;
    vector<int> last, res;
    string str;

    void dfs(int u) {
        int idx = str[u] - 'a', p = last[idx];
        last[idx] = u; 

        for (auto v : adj[u]) {
            int par = last[str[v] - 'a']; 
            if (par == -1)
                par = u; 

            dfs(v);
            res[par] += res[v];
        }
        last[idx] = p;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        str = s;
        adj.resize(n);
        last.assign(26, -1);
        res.assign(n, 1);

        for (int i = 1; i < n; i++)  adj[parent[i]].push_back(i);

        dfs(0);
        return res;
    }
};