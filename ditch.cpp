/*
ID:
PROG: ditch
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 2e9 + 1

int N, M, X, Y, a, i, x, c[202][202], v[202], f[202], r[202];
pair<int, int> p;

int main() {
	freopen("ditch.in", "r", stdin);
	freopen("ditch.out", "w", stdout);
	scanf("%d%d", &N, &M);
	while (N--) scanf("%d%d%d", &X, &Y, &x), c[X][Y] += x;
	while (x) {
		for (i = 0; i < 202; i++) v[i] = f[i] = r[i] = 0;
		priority_queue<pair<int, int> > q;
		q.push(make_pair(INF, 1)), f[1] = INF;
		for (x++;;) {
			if (q.empty()) {x = 0; break;}
			p = q.top(); q.pop();
			if (p.second == M) break;
			if (!v[p.second]++) for (int i = 1; i <= M; i++) if (c[p.second][i] && f[i] < min(p.first, c[p.second][i])) {
				r[i] = p.second, f[i] = min(p.first, c[p.second][i]);
				q.push(make_pair(f[i], i));
			}
		}
		if (x) for (a += f[M], i = M; i != 1; i = r[i]) c[r[i]][i] -= f[M], c[i][r[i]] += f[M];
	}
	printf("%d\n", a);
}
