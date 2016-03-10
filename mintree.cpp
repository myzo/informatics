// Range Tree with Build, Query

#include <bits/stdc++.h>
using namespace std;

int N, V[4004], t[9999], Q, A, B;

int f(int i, int a, int b) {
	if (a == b - 1) t[i] = V[a];
	else t[i] = min(f(2 * i, a, (a + b) / 2), f(2 * i + 1, (a + b) / 2, b));
	return t[i];
}

int q(int i, int a, int b, int x, int y) {
	if (x >= b || y <= a) return 1e9;
	if (x <= a && y >= b) return t[i];
	return min(q(2 * i, a, (a + b) / 2, x, y), q(2 * i + 1, (a + b) / 2, b, x, y));
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &V[i]);
	f(1, 0, N);
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) scanf("%d%d", &A, &B), printf("%d\n", q(1, 0, N, A, B + 1));
}
