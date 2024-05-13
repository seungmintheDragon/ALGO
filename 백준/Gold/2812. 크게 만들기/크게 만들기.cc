#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int n, k;
string m;
int arr[500001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> m;
    string ans = "";
    for (int i = 0; i < n; i++) {
        arr[i] = m[i] - '0';
        //cout << arr[i];
    }
    //cout << "\n";


    k = n - k;
    int sp = -1;
    for (int i = 0; i < k; i++)
    {
        int temp_p = -1;
        sp++;
        for (int j = sp; j <= n - (k - i); j++) {
            if (arr[j] == 9) {
                temp_p = 9;
                sp = j;
                break;
            }

            if (temp_p < arr[j])
            {
                temp_p = arr[j];
                sp = j;
            }
        }
        ans += temp_p + '0';
    }

    cout << ans << "\n";
    return 0;
}