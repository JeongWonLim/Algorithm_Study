#include<iostream>
using namespace std;

//(A+B)%C
int cal_1(int A, int B, int C)
{
	return (A + B) % C;
}

//((A%C)+(B%C)%C)
int cal_2(int A, int B, int C)
{
	return ((A % C) + (B % C) % C);
}

//(A*B)%C
int cal_3(int A, int B, int C)
{
	return (A * B) % C;
}

//((A%C)*(B%C))%C
int cal_4(int A, int B, int C)
{
	return ((A % C) * (B % C)) % C;
}

int main(void)
{
	int A, B, C;

	cin >> A >> B >> C;

	cout << cal_1(A, B, C) << endl;
	cout << cal_2(A, B, C) << endl;
	cout << cal_3(A, B, C) << endl;
	cout << cal_4(A, B, C) << endl;

	return 0;
}