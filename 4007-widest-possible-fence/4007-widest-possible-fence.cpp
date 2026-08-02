class Solution {
public:
    int maximumWidth(vector<int>& planks) {

        unordered_map<int,int> freq;
        vector<int> vals;

        for (int x : planks) {
            if (freq[x] == 0)
                vals.push_back(x);
            freq[x]++;
        }

        unordered_map<long long,int> widthCnt;

        int ans = 1;

        int m = vals.size();

        for (int i = 0; i < m; i++) {

            int x = vals[i];

            widthCnt[x] += freq[x];
            ans = max(ans, widthCnt[x]);

            widthCnt[2LL * x] += freq[x] / 2;
            ans = max(ans, widthCnt[2LL * x]);

            for (int j = i + 1; j < m; j++) {

                int y = vals[j];

                widthCnt[(long long)x + y] += min(freq[x], freq[y]);

                ans = max(ans, widthCnt[(long long)x + y]);
            }
        }

        return ans;
    }
};