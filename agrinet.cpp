/*
ID: mzhaoau1
PROG: agrinet
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

class Compare {
	public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int N, a[110][110];
bool visited[110];

int compute() {
	int answer = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq; // first is node, second is distance
	pair<int, int> current;
	pq.push(mp(0, 0));
	while (pq.size()) {
		current = pq.top();
		pq.pop();
		if (visited[current.first]) continue;
		visited[current.first] = true;
		answer += current.second;
		for (int i = 0; i < N; i++) {
			if (visited[i] || i == current.first) continue;
			pq.push(mp(i, a[current.first][i]));
		}
	}
	return answer;
}

int main() {
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	cout << compute() << endl;
	return 0;
}
