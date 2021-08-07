#include<iostream>
#include<cstdio>
#include<vector>
#define MAXNUM 1000001

int eratos[MAXNUM] = { 0 };
using namespace std;
vector<int>primeNumbers;

// 3~ 1,000,000 까지 에라토스테네스의 체를 이용한 소수구하기
void eratosthenes()
{
	eratos[0] = eratos[1] = eratos[2] = 1;
	for (int i = 3; i < MAXNUM; i++)
	{
		for (int j = 2; i*j < MAXNUM; j++)
		{
			if ((i * j) % i == 0)
				eratos[i * j] = 1;
		}

		if (eratos[i] == 0)
			primeNumbers.emplace_back(i);
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	
	eratosthenes();

	while (cin >> n && n != 0)
	{

		for (vector<int>::iterator iter = primeNumbers.begin(); iter != primeNumbers.end(); iter++)
		{
			if (eratos[n - *iter] == 0)
			{
				cout << n << " = " << *iter << " + " << n - *iter<< "\n";
				break;
			}
		}
	}
	


	return 0;
}
