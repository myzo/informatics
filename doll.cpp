#include <bits/stdc++.h>
using namespace std;

int N, S[1000000];
vector<int> sets (1, 2000000000);

int main() {
	freopen("dollin.txt", "r", stdin);
	freopen("dollout.txt", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &S[i]);
	}
	vector<int>::iterator low;
	for (int i = 0; i < N; i++) {
		low = lower_bound(sets.begin(), sets.end(), S[i]);
		if (low == sets.end()) {
			sets.push_back(S[i]);
		} else {
			sets[low - sets.begin()] = S[i];
		}
	}
	cout << sets.size();
	return 0;
}
