#include<iostream>

using namespace std;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int M, N, x, y;
		int cnt = 1;
		
		cin >> M >> N >> x >> y;

		while (!((((cnt - x) % M) == 0) && (((cnt - y) % N) == 0)) && (cnt <= M * N))
			cnt++;

		if (cnt > M * N)
			cout << "-1" << '\n';
		else
			cout << cnt << '\n';
	}
	return 0;
}