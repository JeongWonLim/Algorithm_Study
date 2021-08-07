#include<iostream>
#include<cstdio>
#define MAXNUM 1000001

using namespace std;

int primeNumbers[MAXNUM] = { 0 };

int main(void)
{
	int N, M;

	cin >> N >> M;
	primeNumbers[1] = 1;

	//1 ~ 1,000,000 ���� �̸� �Ҽ� ���ϱ�
	for (int i = 2; i < MAXNUM; i++)
	{
		for (int j = 2; j * i < MAXNUM; j++)
			if ((j*i) % i == 0)
				primeNumbers[j*i]++;
	}

	for (int i = N; i <= M; i++)
		if (primeNumbers[i] == 0)
			cout << i << '\n'; // endl���� �ð��ʰ�

	return 0;
}
