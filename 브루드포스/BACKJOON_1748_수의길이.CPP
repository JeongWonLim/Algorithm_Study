#include<iostream>

using namespace std;

int main(void)
{
	int N;

	cin >> N;

	int temp = N;
	int cnt = 1;
	int maxlen = 9;
	int len_10 = 9;
	int sum = 9;

	temp /= 10;
	while (temp != 0)
	{
		maxlen = maxlen * 10;
		len_10 = len_10*10 +9;
		cnt++;
		sum += (maxlen * cnt);
		temp /= 10;
	}
	cout << sum - (len_10 - N) * cnt;


	
	return 0;
}