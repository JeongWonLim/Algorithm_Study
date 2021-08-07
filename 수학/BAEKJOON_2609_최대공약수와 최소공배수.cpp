#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{
	int num_1, num_2;

	cin >> num_1 >> num_2;

	int maxNum = num_1 > num_2 ? num_1 : num_2;
	int minNum = num_1 < num_2 ? num_1 : num_2;

	//최대공약수
	int gcd = 0;
	for (int i = 1; i <= minNum; i++)
		if ((num_1 % i == 0) && (num_2 % i == 0))
			gcd = i;
	cout << gcd << endl;

	//최소 공배수
	int lcm = maxNum;
	while (!((lcm % num_1 == 0) && (lcm % num_2 == 0)))
		lcm++;
	cout << lcm;
	
	return 0;
}
