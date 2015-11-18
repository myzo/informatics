#include <bits/stdc++.h>
using namespace std;

int N, P, A, B, g[2], visited[100010], answer;
vector<int> a[100010];

void dfs(int x, bool y) {
	if (visited[x]++) return;
	g[y]++;
	for (int i = 0; i < a[x].size(); i++) dfs(a[x][i], !y);
}

int main() {
	freopen("arthin.txt", "r", stdin);
	freopen("arthout.txt", "w", stdout);
	scanf("%d%d", &N, &P);
	for (int i = 0; i < P; i++) {
		scanf("%d%d", &A, &B);
		a[A].push_back(B);
		a[B].push_back(A);
	}
	for (int i = 1; i <= N; i++, answer += max(g[0], g[1]), g[0] = g[1] = 0) dfs(i, false);
	printf("%d", answer);
}
