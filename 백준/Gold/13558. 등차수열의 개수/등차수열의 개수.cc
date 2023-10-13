#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define int int64_t

int n, mx, ans, v[100001], cnt[2][30001];
int *L = cnt[0], *R = cnt[1];

int32_t main() {
	fastio;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i], R[v[i]]++;
	R[v[1]]--; mx = *max_element(v + 1, v + n + 1);
	for (int i = 2; i <= n - 1; i++) {
		L[v[i - 1]]++; R[v[i]]--; ans += L[v[i]] * R[v[i]];
		for (int j = 1; 1 <= v[i] - j && v[i] + j <= mx; j++) {
			ans += L[v[i] - j] * R[v[i] + j];
			ans += L[v[i] + j] * R[v[i] - j];
		}
	}
	cout << ans << '\n';
}