#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;
        
        int best = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] % a[i] == 0) cnt++;
            }
            best = max(best, cnt);
        }
        cout << n - best << '\n';
    }
    return 0;
}




/*
B. Rhythmic String
time limit per test
2 seconds
memory limit per test
512 megabytes

We call a binary string s of length m periodic if there exists an integer k (1≤k<m) such that si=si+k for every i from 1 to m−k inclusive. The characters of the string are numbered starting from 1. The smallest such k is called the period of the string.

We call a string s rhythmic if it is periodic and among the first p characters of the string (where p is the period of the string), there is exactly one 1.

For example, the string 0010010 is periodic with period p=3 and rhythmic: among the first three characters there is exactly one 1. The string 0110110 is also periodic with period p=3, but it is not rhythmic: among the first three characters there are two 1s.

You are given an array a of n integers and a string s, initially consisting of 1018 zeros. For each element ai, all characters of the string whose indices are divisible by ai are replaced by ones. In other words, the characters at positions ai,2ai,3ai,…, not exceeding the length of the string, become ones. Replacing a character with one again does nothing.

For example, if a=[3,7,5,3], then the string s will begin with 001011101101011...

Before performing these changes, you may remove any elements from array a. Find the minimum number of elements that need to be removed so that the resulting string s is rhythmic.
Input

The first line contains an integer t (1≤t≤5000) — the number of test cases.

The following descriptions of the test cases follow.

The first line of each test case contains an integer n (1≤n≤5000) — the length of array a.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array.

Additional constraints on the input:

    the sum of n over all test cases does not exceed 5000. 

Output

For each test case, output one integer — the minimum number of elements that need to be removed from the array so that string s is rhythmic.
Example
Input
Copy

4
4
3 7 5 3
3
4 8 12
4
6 10 20 30
3
2 3 5

Output
Copy

2
0
1
2

Note

In the first test case, you can remove elements 7 and 5. Then the string will begin with 001001001... and will be rhythmic with period 3.

In the second test case, nothing needs to be removed. The string will begin with 000100010001... and will be rhythmic with period 4.

In the third test case, it is enough to remove element 6. The resulting string will be rhythmic with period 10.

In the fourth test case, you need to keep any one element of the array.
*/