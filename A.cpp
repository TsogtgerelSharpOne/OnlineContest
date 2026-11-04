#include<bits/stdc++.h>
using namespace std;
int main(){
	int test;
	cin >> test;
	
	while(test--){
		int l,r;	cin >> l >> r;
		if(l > 0 && r > 0){
			cout << r - l << '\n';
			continue;
		}
		
		if(l < 0 && r < 0){
			cout << abs(l) - abs(r) << '\n';
			continue;
		}
		
		cout << max(abs(r + l ) - 1, 0) << '\n';
	}
	return 0;
}










































/*
https://codeforces.com/contest/2283/problem/A
A. Numbers on the Board
time limit per test
2 seconds
memory limit per test
512 megabytes

All integers from l to r inclusive are written on the board, each exactly once.

We call a number on the board beautiful if it is equal to the sum of all numbers on the board, including this number itself. For example, if the numbers −4, −1, 2, 3, 5 are written on the board, then the number 5 is beautiful.

You may erase any numbers from the board, but at least one number must remain. Find the minimum number of numbers that need to be erased so that after that there is at least one beautiful number on the board. It is not necessary to erase any numbers if there is already a beautiful number on the board.
Input

The first line contains an integer t (1≤t≤104) — the number of test cases.

Each test case consists of one line containing two integers l and r (−100≤l≤r≤100).
Output

For each test case, print one integer — the minimum number of numbers that need to be erased from the board.
Example
Input
Copy

8
0 0
2 6
-5 -3
-2 2
-2 3
-2 5
-6 2
0 4

Output
Copy

0
4
2
0
0
2
3
3

Note

For the test cases from the statement, you should do the following:

    Leave the number 0. It is equal to the sum of all numbers on the board, so nothing needs to be erased.
    Erase the numbers 2, 3, 4, 5. Only the number 6 will remain on the board, and it will be beautiful.
    Erase the numbers −4 and −3. Only the number −5 will remain on the board, and it will be beautiful.
    Do not erase anything. The numbers −2, −1, 0, 1, 2 will remain on the board. Their sum is 0, so the number 0 is beautiful.
    Do not erase anything. The numbers −2, −1, 0, 1, 2, 3 will remain on the board. Their sum is 3, so the number 3 is beautiful.
    Erase the numbers 4 and 5. The numbers −2, −1, 0, 1, 2, 3 will remain on the board. Their sum is 3, so the number 3 is beautiful.
    Erase the numbers −6, −5, −3. The numbers −4, −2, −1, 0, 1, 2 will remain on the board. Their sum is −4, so the number −4 is beautiful.
    Erase the numbers 1, 2, 3. The numbers 0 and 4 will remain on the board. Their sum is 4, so the number 4 is beautiful. 
*/