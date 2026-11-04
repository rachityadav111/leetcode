
class Solution {
    struct MedianCost {
        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;

        void balance() {
            while (left.size() > right.size() + 1) {
                int x = *left.rbegin();
                left.erase(prev(left.end()));
                sumLeft -= x;
                right.insert(x);
                sumRight += x;
            }

            while (left.size() < right.size()) {
                int x = *right.begin();
                right.erase(right.begin());
                sumRight -= x;
                left.insert(x);
                sumLeft += x;
            }
        }

        void add(int x) {
            if (left.empty() || x <= *left.rbegin()) {
                left.insert(x);
                sumLeft += x;
            } else {
                right.insert(x);
                sumRight += x;
            }
            balance();
        }

        void remove(int x) {
            auto it = left.find(x);

            if (it != left.end()) {
                left.erase(it);
                sumLeft -= x;
            } else {
                it = right.find(x);
                right.erase(it);
                sumRight -= x;
            }

            balance();
        }

        long long cost() {
            long long median = *left.rbegin();

            return median * (long long)left.size() - sumLeft
                 + sumRight - median * (long long)right.size();
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Calculate minimum cost for every window of size x.
        vector<long long> cost(n - x + 1);

        MedianCost window;

        for (int i = 0; i < x; i++) {
            window.add(nums[i]);
        }

        cost[0] = window.cost();

        for (int i = x; i < n; i++) {
            window.remove(nums[i - x]);
            window.add(nums[i]);
            cost[i - x + 1] = window.cost();
        }

        // DP: minimum cost to select j non-overlapping windows
        // among the first i elements.
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Skip the current element.
                curr[i] = curr[i - 1];

                // Take a window ending at i - 1.
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
