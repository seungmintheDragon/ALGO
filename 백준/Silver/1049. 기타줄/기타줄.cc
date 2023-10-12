#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A;
vector<int> B;

void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
}

void solution()
{
    int a = A[0];
    int b = B[0];
    int num1 = a * ceil(double(N) / 6);
    int num2 = b * N;
    int num3 = a * floor(N / 6) + b * (N % 6);
    int ans = min(num1, num2);
    ans = min(ans, num3);

    cout << ans << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solution();
    return 0;
}