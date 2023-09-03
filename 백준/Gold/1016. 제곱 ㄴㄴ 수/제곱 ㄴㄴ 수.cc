#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	long long min, max;
	cin >> min >> max;
	int N = max - min + 1;
	int sqrt_max = (int)(ceil(sqrt(max)));
	
	//소수 벡터 저장
	vector<bool> is_primes(sqrt_max + 1, true);
	// 소수의 제곱수 벡터
	vector<long long> square_prime;
	// min 부터 max까지 배열
	vector<bool> nums(N, true);
	int multi_p;
	for (int i = 2; i <= sqrt_max; i++)
	{
		if(is_primes[i])
		{
			multi_p = i + i;
			while (multi_p <= sqrt_max)
			{
				is_primes[multi_p] = false;
				multi_p += i;
			}
		}
	}

	for (int i = 2; i <= sqrt_max; i++)
	{
		if (is_primes[i])
		{
			square_prime.push_back((long long)i * (long long)i);
		}
	}
	long long multi_sq;
	for (auto& i :square_prime)
	{
		multi_sq = (long long)(ceil(((double)min) / ((double)i))) * i;
		while (multi_sq <= max)
		{
			nums[multi_sq - min] = false;
			multi_sq += i;
		}
	}

	int ans = 0;
	for (const auto& i : nums) {
		if (i)
		{
			ans++;
		}
	}

	cout << ans << endl;
	
	return 0;
}