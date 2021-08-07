#include<iostream>
#include<string>
using namespace std;
int cnt = 0;
int n;

int cal(int nSum)
{
	if (nSum > n)
		return 0;
	else if (nSum == n)
		return 1;

	return cal(nSum + 1) + cal(nSum + 2) + cal(nSum + 3);
}

int main(void)
{
	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n;
		cnt = 0;

		for (int j = 1; j <= 3; j++)
		{
			cnt += cal(j);
		}
		cout << cnt << endl;
	}
	return 0;
}