#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> l(n + 1, 0), r(n + 1, 0);
        for (int i = 2; i <= n; i++) cin >> l[i] >> r[i];

        int sz = 1;
        while (sz < n + 1) sz <<= 1;
        const int INF = INT_MAX;
        vector<int> seg(2 * sz, INF);

        auto update = [&](int pos, int val) {
            pos += sz;
            seg[pos] = val;
            for (pos >>= 1; pos >= 1; pos >>= 1)
                seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
        };
        auto query = [&](int lo, int hi) {
            int res = INF;
            for (lo += sz, hi += sz + 1; lo < hi; lo >>= 1, hi >>= 1) {
                if (lo & 1) res = min(res, seg[lo++]);
                if (hi & 1) res = min(res, seg[--hi]);
            }
            return res;
        };

        vector<int> m(n + 1, 0);
        m[1] = 1;
        update(1, 1);
        for (int i = 2; i <= n; i++) {
            m[i] = min(l[i], query(l[i], r[i]));
            update(i, m[i]);
        }

        vector<int> nxt(n + 2, n + 1), dsu(n + 2);
        for (int j = 0; j <= n + 1; j++) dsu[j] = j;
        auto find = [&](int x) {
            while (dsu[x] != x) {
                dsu[x] = dsu[dsu[x]];
                x = dsu[x];
            }
            return x;
        };
        for (int x = 2; x <= n; x++) {
            for (int j = find(l[x]); j <= r[x]; j = find(j)) {
                nxt[j] = x;
                dsu[j] = j + 1;
            }
        }

        vector<vector<int>> byNxt(n + 2), byR(n + 1);
        for (int j = 1; j <= n; j++) byNxt[nxt[j]].push_back(j);
        for (int i = 2; i <= n; i++) byR[r[i]].push_back(i);

        vector<long long> bit(n + 1, 0);
        auto add = [&](int p, long long d) {
            for (; p <= n; p += p & -p) bit[p] += d;
        };
        auto pref = [&](int p) {
            long long res = 0;
            for (; p > 0; p -= p & -p) res += bit[p];
            return res;
        };

        for (int j : byNxt[n + 1]) add(j, 1);
        long long total = 0;
        for (int R = n; R >= 1; R--) {
            if (R + 1 <= n)
                for (int j : byNxt[R + 1]) add(j, 1);
            for (int i : byR[R]) total += pref(r[i]) - pref(l[i] - 1);
        }
        cout << total << '\n';
    }
    return 0;
}

/*
F. Minimize the Graph
time limit per test
3 seconds
memory limit per test
512 megabytes

You are given a directed graph with n vertices, numbered from 1 to n. The graph is constructed as follows: for each vertex i from 2 to n, you are given two integers li and ri (1≤li≤ri<i). For each integer j∈[li,ri], the graph contains a directed edge from j to i. There are no other edges in the graph.

Consider a second directed graph on the same n vertices. For any two distinct vertices x and y, a path from x to y must exist in the second graph if and only if it exists in the first graph.

Find the minimum possible number of edges in the second graph.
Input

The first line contains one integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains one integer n (2≤n≤3⋅105) — the number of vertices.

The next n−1 lines describe the edges of the graph. The i-th of these lines contains two integers li+1 and ri+1 (1≤li+1≤ri+1≤i).

Additional constraints on the input:

    the sum of n over all test cases does not exceed 3⋅105. 

Output

For each test case, print one integer — the minimum possible number of edges in the second graph.
Example
Input
Copy

5
5
1 1
1 2
2 3
2 4
6
1 1
1 1
2 3
2 3
4 5
5
1 1
1 2
1 3
1 4
6
1 1
1 1
1 1
2 4
2 4
6
1 1
1 2
1 1
2 4
3 5

Output
Copy

4
8
4
9
6

Note

In the first test case, you can add the edges 1→2, 2→3, 3→4, and 4→5 to the second graph.

In the second test case, you can add the edges 1→2, 1→3, 2→4, 3→4, 2→5, 3→5, 4→6, and 5→6 to the second graph.
*/