class Solution {
public:

    struct Node {
        int prod;
        array<int, 5> cnt;

        Node() {
            prod = 1;
            cnt.fill(0);
        }
    };

    int n, k;
    vector<Node> tree;

    Node merge(const Node& A, const Node& B) {

        Node C;

        C.prod = (A.prod * B.prod) % k;

        // Prefixes completely inside A
        for (int r = 0; r < k; r++) {
            C.cnt[r] += A.cnt[r];
        }

        // Prefixes that contain all of A
        // and then some prefix of B
        for (int r = 0; r < k; r++) {

            int newR = (A.prod * r) % k;

            C.cnt[newR] += B.cnt[r];
        }

        return C;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if (l == r) {

            int val = nums[l] % k;

            tree[node].prod = val;
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] =
            merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r,
                int index, int value) {

        if (l == r) {

            int val = value % k;

            tree[node].prod = val;
            tree[node].cnt.fill(0);
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, value);
        }
        else {
            update(node * 2 + 1, mid + 1, r,
                   index, value);
        }

        tree[node] =
            merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r,
                         ql, qr);
        }

        Node left =
            query(node * 2, l, mid, ql, qr);

        Node right =
            query(node * 2 + 1, mid + 1, r,
                  ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {

        this->n = nums.size();
        this->k = k;

        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> result;
        result.reserve(queries.size());

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update nums[index]
            update(1, 0, n - 1,
                   index, value);

            // Query nums[start ... n-1]
            Node res =
                query(1, 0, n - 1,
                      start, n - 1);

            result.push_back(res.cnt[x]);
        }

        return result;
    }
};