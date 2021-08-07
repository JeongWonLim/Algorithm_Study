#include<iostream>

using namespace std;

int main(void)
{
	int N;
	long long sum = 0; 

	cin >> N;


	for (int i = 1; i <= N; i++)
	{
		sum += (i * (N / i));
	}

	cout << sum << endl;
	
	return 0;
}
