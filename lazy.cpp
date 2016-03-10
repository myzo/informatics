// Range Tree with Build, Query, Lazy

#include <bits/stdc++.h>
using namespace std;

int N, V[1001], Q, A, B, X, t[9999], s[9999], l[9999];

int build(int i, int a, int b) {
	if (a == b - 1) t[i] = V[a], s[a] = i;
	else t[i] = min(build(2 * i, a, (a + b) / 2), build(2 * i + 1, (a + b) / 2, b));
	return t[i];
}

int query(int i, int a, int b, int x, int y) {
	if (x >= b || y <= a) return 1e9;
	if (l[i]) {
		t[i] += l[i];
		if (a != b - 1) l[2 * i] += l[i], l[2 * i + 1] += l[i];
		l[i] = 0;
	}
	if (x <= a && y >= b) return t[i];
	return min(query(2 * i, a, (a + b) / 2, x, y), query(2 * i + 1, (a + b) / 2, b, x, y));
}

int update(int i, int a, int b, int x, int y, int v) {
	if (l[i]) {
		t[i] += l[i];
		if (a != b - 1) l[2 * i] += l[i], l[2 * i + 1] += l[i];
		l[i] = 0;
	}
	if (x >= b || y <= a) return t[i];
	if (x <= a && y >= b) {
		t[i] += v;
		if (a != b - 1) l[2 * i] += v, l[2 * i + 1] += v;
	} else t[i] = min(update(2 * i, a, (a + b) / 2, x, y, v), update(2 * i + 1, (a + b) / 2, b, x, y, v));
	return t[i];
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &V[i]);
	build(1, 0, N);
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d%d%d", &A, &B, &X); // get minimum value between [A, B]
		if (A == -1) printf("%d\n", query(1, 0, N, B, X + 1));
		else update(1, 0, N, A, B + 1, X);
	}
}
