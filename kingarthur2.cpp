#include <bits/stdc++.h>
using namespace std;

int N, P, A, B, answer;
vector<int> a[100010];
bool visited[100010];

void dfs(int x) {
	if (visited[x]) return;
	int g[2] {0};
	pair<int, int> c;
	stack<pair<int, int> > s;
	s.push(make_pair(x, 0));
	while (s.size()) {
		c = s.top(); s.pop();
		if (visited[c.first]) continue;
		visited[c.first] = true;
		g[c.second % 2]++;
		for (int i = 0; i < a[c.first].size(); i++) {
			s.push(make_pair(a[c.first][i], c.second + 1));
		}
	}
	answer += max(g[0], g[1]);
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
	for (int i = 1; i <= N; i++) dfs(i);
	printf("%d", answer);
}
