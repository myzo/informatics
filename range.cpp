/*
ID:
PROG: range
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int N, c[300][300], o[300];

int main() {
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);
	scanf("%d\n", &N);
	for (int i = 1; i <= N; i++, getchar()) {
		for (int j = 1; j <= N; j++) {
			if (getchar() == '1') {
				c[i][j] = min(min(c[i - 1][j], c[i][j - 1]), c[i - 1][j - 1]) + 1;
				for (int k = c[i][j]; k >= 2; k--) o[k]++;
			}
		}
	}
	for (int i = 2; o[i] != 0; i++) printf("%d %d\n", i, o[i]);
}
