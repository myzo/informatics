/*
ID:
PROG: stamps
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int K, N, c[2000100], v[60], a;

int main() {
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	scanf("%d%d", &K, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	while (c[a++] <= K) {
		for (int j = 0; j < N; j++) {
			if (a >= v[j] && (c[a - v[j]] + 1 < c[a] || !c[a])) {
				c[a] = c[a - v[j]] + 1;
			}
		}
	}
	cout << a - 2 << endl;
	return 0;
}
