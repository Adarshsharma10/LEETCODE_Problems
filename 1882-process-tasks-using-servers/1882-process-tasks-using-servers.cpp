#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_servers;

        for (int i = 0; i < servers.size(); ++i) {
            free_servers.push({servers[i], i});
        }

        vector<int> ans(tasks.size());
        long long time = 0;

        for (int i = 0; i < tasks.size(); ++i) {
            time = max(time, (long long)i);

            if (free_servers.empty()) {
                time = busy_servers.top().first;
            }


            while (!busy_servers.empty() && busy_servers.top().first <= time) {
                int idx = busy_servers.top().second;
                busy_servers.pop();
                free_servers.push({servers[idx], idx});
            }
            auto [weight, server_idx] = free_servers.top();
            free_servers.pop();

            ans[i] = server_idx;

            busy_servers.push({time + tasks[i], server_idx});
        }

        return ans;
    }
};