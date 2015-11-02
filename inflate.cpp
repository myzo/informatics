/*
ID:
PROG: inflate
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int M, N, c[10010], a, b;

int main() {
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &a, &b);
		for (int j = 1; j <= M; j++) {
			if (j >= b) c[j] = max(c[j - b] + a, c[j]);
		}
	}
	cout << c[M] << endl;
	return 0;
}
