#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;

	vector<int> num;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		num.push_back(x);
	}

	vector<int> LtoR(n);
	vector<int> RtoL(n);

	LtoR[0] = num[0];
	RtoL[n - 1] = num.back();

	for (int i = 1; i <= n - 1; i++) {
		int val = LtoR[i - 1];
		LtoR[i] = gcd(max(val, num[i]), min(val, num[i]));
	}

	for (int i = n - 2; i >= 0; i--) {
		int val = RtoL[i + 1];
		RtoL[i] = gcd(max(val, num[i]), min(val, num[i]));
	}

	int result = -1;
	int except = -1;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			result = max(result, RtoL[1]);
			except = num[i];
		}
		else if (i == n - 1) {
			if (result < LtoR[n-2]) {
				result = LtoR[n-2];
				except = num[i];
			}
		}
		else {
			if (result < gcd(LtoR[i - 1], RtoL[i + 1])) {
				result = gcd(LtoR[i - 1], RtoL[i + 1]);
				except = num[i];
			}
		}
	}

	if (except % result == 0) {
		cout << -1 << "\n";
	}
	else {
		cout << result << " " << except << "\n";
	}

	return 0;
}