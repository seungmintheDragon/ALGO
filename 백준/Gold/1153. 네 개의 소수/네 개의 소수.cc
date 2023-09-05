#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    // 소수 구하기
    int sqrt_N = (int)(ceil(sqrt(N)));
    vector<bool> is_primes(N + 1, true);
    int next_i;
    for (int i = 2; i <= sqrt_N; i++) {
        if (is_primes[i]) {
            next_i = i + i;
            while (next_i <= N) {
                is_primes[next_i] = false;
                next_i += i;
            }
        }
    }
    //골드바흐의 추측 : '2보다 큰 모든 짝수는 두 소수의 합으로 표현가능하다'
    vector<int> ans;
    if (N < 8) ans.push_back(-1);
    else {
        if (N % 2) {
            ans.push_back(2);
            ans.push_back(3);
            for (int i = 2; i <= N; i++) {
                if (is_primes[i] && is_primes[N - i - 5]) {
                    ans.push_back(i);
                    ans.push_back(N - i - 5);
                    break;
                }
            }
        }
        else {
            ans.push_back(2);
            ans.push_back(2);
            for (int i = 2; i <= N; i++) {
                if (is_primes[i] && is_primes[N - i - 4]) {
                    ans.push_back(i);
                    ans.push_back(N - i - 4);
                    break;
                }
            }
        }
    }
    for (auto p : ans) cout << p << " ";
    cout << endl;

    return 0;
}