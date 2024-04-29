#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long sol[5001];
long long ans[3];
long long tmp = 1e18;

void solve() {
    sort(sol, sol + n);

    for (int i = 0; i <= n - 3; i++) {
        int st = i + 1;
        int en = n - 1;
        while (st < en) {
            long long sum_sol = sol[i] + sol[st] + sol[en];
            if (abs(sum_sol) < tmp) {
                tmp = abs(sum_sol);
                ans[0] = sol[i];
                ans[1] = sol[st];
                ans[2] = sol[en];
            }

            if (sum_sol < 0) st++;
            else en--;
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2];
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sol[i];
    }
    solve();


    return 0;
}

