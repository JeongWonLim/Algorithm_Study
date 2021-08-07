#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{
	int T;
	int cnt = 0;
	
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;

		if (n != 1)
		{
			int check = 0;
			for (int j = 2; j < n; j++)
			{
				if (n % j == 0)
					check = 1;
					break;
			}

			if (check == 0)
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}
