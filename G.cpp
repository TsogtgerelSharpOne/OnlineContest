#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> k(n);
    for (auto &x : k) cin >> x;

    vector<int> inmask(n, 0);
    for (int e = 0; e < m; e++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        inmask[v] |= 1 << u;
    }

    vector<int> need(n);
    for (int v = 0; v < n; v++)
        need[v] = __builtin_popcount(inmask[v]) - k[v] + 1;

    const int S = 1 << n;
    const int LOG = 60;
    vector<vector<int>> jump(LOG, vector<int>(S));
    for (int s = 0; s < S; s++) {
        int ns = 0;
        for (int v = 0; v < n; v++)
            if (__builtin_popcount(s & inmask[v]) >= need[v]) ns |= 1 << v;
        jump[0][s] = ns;
    }
    for (int b = 1; b < LOG; b++)
        for (int s = 0; s < S; s++) jump[b][s] = jump[b - 1][jump[b - 1][s]];

    string out;
    while (q--) {
        long long T;
        cin >> T;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        vector<long long> xs = a;
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        vector<int> cnt(n, 0);
        for (long long x : xs) {
            int s = 0;
            for (int v = 0; v < n; v++)
                if (a[v] >= x) s |= 1 << v;
            for (int b = 0; b < LOG; b++)
                if ((T >> b) & 1) s = jump[b][s];
            for (int v = 0; v < n; v++)
                if ((s >> v) & 1) cnt[v]++;
        }
        for (int v = 0; v < n; v++) {
            out += to_string(xs[cnt[v] - 1]);
            out += (v + 1 < n) ? ' ' : '\n';
        }
    }
    cout << out;
    return 0;
}

/*
G. Order Statistics on the Graph
time limit per test
7 seconds
memory limit per test
512 megabytes

You are given a directed graph with n vertices, numbered from 1 to n. Each vertex has at least one incoming edge. The graph may contain self-loops, but it has no multiple edges. For each vertex v, an integer kv is given, ranging from 1 to the number of incoming edges of that vertex.

Each vertex has a number written on it. Every second, all the numbers are updated as follows. For a vertex v, take the numbers at the vertices u for which there is an edge u→v, sort them in non-decreasing order, and update vertex v with the number at the position kv. Positions in the sorted list are numbered starting from 1. In other words, the new number at vertex v is the kv-th order statistic of the array consisting of the numbers at the vertices u for which there is an edge u→v.

All vertices are updated simultaneously: only the numbers from before the current update are used to compute the new numbers. If a vertex has a self-loop, its own number also affects the update.

You have to process q queries of the following form:

    t a1 a2 ... an — determine the numbers that will be written on the vertices of the graph after t seconds if their initial numbers are a1,a2,…,an. 

Input

The first line contains three integers n, m, and q (1≤n≤20; n≤m≤n2; 1≤q≤105) — the number of vertices, edges, and queries, respectively.

The second line contains n integers k1,k2,…,kn. For each vertex v, it holds that 1≤kv≤dv, where dv is the number of incoming edges of that vertex.

Each of the next m lines contains two integers u and v (1≤u,v≤n), denoting an edge from u to v. All ordered pairs (u,v) are distinct.

Each of the next q lines contains n+1 integers t,a1,a2,…,an (0≤t≤1018; 1≤ai≤109) — the parameters of a query.
Output

For each query, print n integers — the values on vertices 1,2,…,n after t seconds.
Examples
Input
Copy

3 3 4
1 1 1
1 2
2 3
3 1
0 4 8 15
1 4 8 15
2 4 8 15
1000000000000000000 1 2 3

Output
Copy

4 8 15
15 4 8
8 15 4
3 1 2

Input
Copy

2 4 3
1 2
1 1
1 2
2 1
2 2
1 10 1
1000000000000000000 7 7
0 1000000000 1

Output
Copy

1 10
7 7
1000000000 1

Input
Copy

4 8 4
1 2 2 1
1 1
2 1
1 2
2 2
3 2
2 3
4 3
3 4
1 8 3 5 1
2 8 3 5 1
3 8 3 5 1
1000000000000000000 8 3 5 1

Output
Copy

3 5 3 5
3 3 5 3
3 3 3 5
3 3 5 3

Note

In the first example, each number moves to the next vertex of the cycle. After three seconds, all numbers return to their original positions.

In the second example, the first vertex takes the minimum of the two numbers, while the second takes the maximum.

In the third example, the array [8,3,5,1] becomes [3,5,3,5] after the first update and [3,3,5,3] after the second update.
*/