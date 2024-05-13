#include <iostream>
#include <stack>;

using namespace std;

int n;
int arr[100001], cnt[100001], idx[100001];
stack<pair<int, int>> to_left, to_right;

int min_idx(int a,int b,int s) {
	if (abs(a - s) == abs(b - s)) {
		return min(a, b);
	}

	if (abs(a - s) < abs(b - s)) {
		return a;
	}

	return b;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		while (!to_right.empty() && to_right.top().first <= arr[i]) to_right.pop();
		cnt[i] += to_right.size();

		if (!to_right.empty()) idx[i] = to_right.top().second;
		to_right.push({ arr[i], i });
	}

	for (int i = n; i >= 1; i--) {
		while (!to_left.empty() && to_left.top().first <= arr[i]) to_left.pop();
		cnt[i] += to_left.size();

		if (!to_left.empty()) {
			if (idx[i] == 0) idx[i] = to_left.top().second;
			else {
				idx[i] = min_idx(idx[i], to_left.top().second, i);
			}
		}
		to_left.push({ arr[i], i });
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			cout << 0 << "\n";
			continue;
		}

		cout << cnt[i] << " " << idx[i] << "\n";
	}
	return 0;
}