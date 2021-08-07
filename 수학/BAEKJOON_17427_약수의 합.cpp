#include<iostream>
#include<cstdio>
using namespace std;
long long sum[1000001] = { 0 };

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	long long N;
	cin >> T;

	for (int i = 1; i < 1000001; i++)
	{
		for (int j = 1; i * j < 1000001; j++)
			sum[i * j] += i;

		sum[i] += sum[i - 1];
	}

	for (int i = 0; i < T; i++)
	{
		cin >> N;

		cout << sum[N] << '\n';
	}
	
	return 0;
}
