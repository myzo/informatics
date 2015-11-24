/*
ID:
PROG: game1
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int N, b[111], c[111][111], s;

int z(int x, int y) {
    if (c[x][y]) return c[x][y];
    if (x > y) c[x][y] = 0;
    else if (y - x == 1) c[x][y] = max(b[x], b[y]);
    else c[x][y] = max(b[x] + min(z(x + 1, y - 1), z(x + 2, y)), b[y] + min(z(x + 1, y - 1), z(x, y - 2)));
    return c[x][y];
}

int main() {
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &b[i]), s += b[i];
    z(0, N - 1);
    printf("%d %d\n", c[0][N - 1], s - c[0][N - 1]);
}
