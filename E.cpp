#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long MOD = 998244353;
    const int MAXN = 5000;

    vector<long long> bell(MAXN + 1);
    vector<long long> prev = {1};
    bell[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        vector<long long> cur = {prev.back()};
        for (size_t j = 0; j < prev.size(); j++)
            cur.push_back((cur.back() + prev[j]) % MOD);
        bell[i] = cur[0];
        prev = move(cur);
    }

    struct St {
        int val;
        long long ways;
    };

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int z0 = 0;
        for (char ch : s) if (ch == '0') z0++;
        int z1 = n - z0;

        vector<vector<St>> L(4, vector<St>(n + 1, St{-1, 0}));
        L[0][0] = St{0, 1};

        auto upd = [&](St &st, int v, long long w) {
            if (v > st.val) {
                st.val = v;
                st.ways = w;
            } else if (v == st.val) {
                st.ways = (st.ways + w) % MOD;
            }
        };

        for (int i = 0; i < n; i++) {
            vector<St> &cur = L[i % 4];
            for (int c = 0; c <= n; c++) {
                if (cur[c].val < 0) continue;
                int v = cur[c].val;
                long long w = cur[c].ways;

                upd(L[(i + 1) % 4][c], v, w);

                if (i + 1 < n && s[i] != s[i + 1]) {
                    int z = (s[i] == '0') + (s[i + 1] == '0');
                    upd(L[(i + 2) % 4][c + z], v + 2, w);
                }
                if (i + 2 < n && s[i] == s[i + 2] && s[i] != s[i + 1]) {
                    int z = (s[i] == '0') + (s[i + 1] == '0') + (s[i + 2] == '0');
                    upd(L[(i + 3) % 4][c + z], v + 3, w);
                }
            }
            for (auto &st : cur) st = St{-1, 0};
        }

        vector<St> &fin = L[n % 4];
        int M = -1;
        for (int c = 0; c <= n; c++) M = max(M, fin[c].val);

        long long cnt = 0;
        for (int c = 0; c <= n; c++) {
            if (fin[c].val != M) continue;
            int cov1 = M - c;
            if (cov1 < 0 || c > z0 || cov1 > z1) continue;
            long long term = fin[c].ways * bell[z0 - c] % MOD * bell[z1 - cov1] % MOD;
            cnt = (cnt + term) % MOD;
        }

        cout << n + M << ' ' << cnt << '\n';
    }
    return 0;
}

/*
E. Partition of a Binary String
time limit per test
2 seconds
memory limit per test
512 megabytes

You are given a binary string s of length n. The characters of the string are numbered from 1 to n.

You have to partition all integers from 1 to n into nonempty sets so that each integer belongs to exactly one set. For each pair of distinct integers x and y in the same set, at least one of the following conditions must hold:

    sx=sy;
    |x−y|=1. 

For a set M, let f(M) be the number of distinct characters among sx over all x∈M. The cost of the set M is |M|⋅f(M), where |M| is the number of elements in M. The cost of a partition is the sum of the costs of all its sets.

For example, if the string s is 10001000, the partition into the sets {1,2},{3,8},{4,5,6},{7} is valid, and its cost is 2⋅2+2⋅1+3⋅2+1⋅1=13.

Find the maximum possible cost of a partition and the number of partitions with this cost. Partitions that differ only in the order of the sets or the order of elements within the sets are considered the same. Output the number of partitions modulo 998244353.
Input

The first line contains one integer t (1≤t≤500) — the number of test cases.

The first line of each test case contains one integer n (1≤n≤5000) — the length of the string.

The second line of each test case contains one string s of length n, consisting only of the characters 0 and 1.
Output

For each test case, print two integers: the maximum cost of a partition and the number of partitions with this cost (taken modulo 998244353).
Example
Input
Copy

3
8
10001000
6
000111
8
01010101

Output
Copy

13 5
8 4
16 4

2026-11-04 18:45:00
	
Announcement
	
Problem E. Partition of a Binary String
*****
There are no constraints on the sum of "n" over all test cases.
*/