
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Sort logs by TIME, not server_id.
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int m = queries.size();

        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(m, 0);

        int left = 0, right = 0;
        int active = 0;
        int L = logs.size();

        for (auto [time, idx] : q) {
            int start = time - x;

            // Include logs up to query time.
            while (right < L && logs[right][1] <= time) {
                int id = logs[right][0];

                if (freq[id] == 0)
                    active++;

                freq[id]++;
                right++;
            }

            // Remove logs before the interval.
            while (left < right && logs[left][1] < start) {
                int id = logs[left][0];

                freq[id]--;

                if (freq[id] == 0)
                    active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
