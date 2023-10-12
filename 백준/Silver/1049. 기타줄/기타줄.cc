#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int A = 1001;
int B = 1001;

void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        A = min(a, A);
        B = min(b, B);
    }
}

void solution()
{
    cout << min(A * (N/6 + 1), min(N/6 * A + N%6 * B , B * N))<< endl;
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