#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int n;
int ans = -987654321;
string s;

int Cal (int a, int b, char c){
	//cout << a << " " << b << " " << c << "\n";
	switch (c)
	{
	case '+': a += b;	break;
	case '-': a -= b;	break;
	case '*': a *= b;	break;
	}
	return a;
}

void Dfs(int cur, int sums, bool bef) {
	if (cur > n) {
		ans = max(sums, ans);
		//cout << sums << "\n";
		return;
	}

	// 괄호 안치고

	Dfs(cur + 2, Cal(sums, s[cur + 1] - '0', s[cur]), true);
	// 괄호 치고
	if (cur <= n - 2)
	{
		Dfs(cur + 4, Cal(sums, Cal(s[cur + 1] - '0', s[cur + 3] - '0', s[cur + 2]), s[cur]), false);
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s;
	s = "0+" + s;
	//cout << s;
	Dfs(1, 0, true);
	cout << ans;
    return 0;
}
