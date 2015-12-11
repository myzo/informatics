#include <bits/stdc++.h>
using namespace std;

struct Dish {
	int student, teacher, gap; // positive gap means first is greater than second
	bool operator<(const Dish& d) {
	  return abs(gap) > abs(d.gap);
	}
};

bool comp(int x, int y) {return x > y;}

int N, A, B, a, x, y;
Dish dishes[200010];
vector<int> ps, pt;

int main() {
	freopen("restin.txt", "r", stdin);
	freopen("restout.txt", "w", stdout);
	scanf("%d%d%d", &N, &A, &B);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &x, &y);
		if (x < 0 && y < 0) continue;
		dishes[i].student = x; dishes[i].teacher = y;
		dishes[i].gap = max(0, dishes[i].student) - max(0, dishes[i].teacher);
	}
	sort(dishes, dishes + N);
	for (int i = 0; i < N; i++) {
		if (!A && !B) break;
		if (dishes[i].gap > 0) {
			if (A) {
				a += dishes[i].student;
				A--;
			} else if (dishes[i].teacher > 0) {
				pt.push_back(dishes[i].teacher);
			}
		} else if (dishes[i].gap < 0) {
			if (B) {
				a += dishes[i].teacher;
				B--;
			} else if (dishes[i].student > 0) {
				ps.push_back(dishes[i].student);
			}
		} else if (dishes[i].student > 0) {
			if (A) {
				a += dishes[i].student;
				A--;
			} else {
				a += dishes[i].teacher;
				B--;
			}
		}
	}
	sort(ps.begin(), ps.end(), comp);
	sort(pt.begin(), pt.end(), comp);
	for (int i = 0; i < pt.size() && B > 0; i++) a += pt[i], B--;
	for (int i = 0; i < ps.size() && A > 0; i++) a += ps[i], A--;
	printf("%d\n", a);
}
