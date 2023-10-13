#include <iostream>
#include <algorithm>

#define MAX 301

using namespace std;

int arr[MAX];
int DP[MAX];
int N;

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
}

void solution()
{
	DP[1] = arr[1];
	DP[2] = arr[1] + arr[2];
	DP[3] = max(arr[3] + arr[1], arr[3] + arr[2]);

	for (int i = 4; i <= N; i++)
	{
		DP[i] = max(arr[i] + DP[i - 2], arr[i] + DP[i - 3] + arr[i - 1]);
	}

	cout << DP[N] << '\n';
}

int main()
{
	input();
	solution();
	return 0;
}

