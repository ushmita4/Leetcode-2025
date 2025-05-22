class Fenwick {
    int N;
    vector<int> f;
public:
    Fenwick(int n): N(n), f(n+1, 0) {}
    void add(int i, int v) {
        for(++i; i <= N; i += i&-i) f[i] += v;
    }
    int sum(int i) const {
        int s = 0;
        for(++i; i > 0; i -= i&-i) s += f[i];
        return s;
    }
    void range_add(int l, int r, int v) {
        add(l, v);
        if (r+1 < N) add(r+1, -v);
    }
};

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<array<int,3>> Q(m);
        for (int i = 0; i < m; i++)
            Q[i] = {queries[i][0], queries[i][1], i};
        sort(Q.begin(), Q.end(),
             [](auto &A, auto &B){ return A[0] < B[0]; });
        priority_queue<pair<int,int>> pq;
        Fenwick fenw(n);
        int ptr = 0, applied = 0;
        for (int i = 0; i < n; i++) {
            while (ptr < m && Q[ptr][0] <= i) {
                pq.emplace(Q[ptr][1], Q[ptr][2]);
                ptr++;
            }
            while (fenw.sum(i) < nums[i]) {
                while (!pq.empty() && pq.top().first < i)
                    pq.pop();
                if (pq.empty()) 
                    return -1;     

                auto [r, idx] = pq.top(); 
                pq.pop();
                applied++;
                int l0 = queries[idx][0],
                    r0 = queries[idx][1];
                fenw.range_add(l0, r0, 1);
            }
        }
        return m - applied;
    }
};
