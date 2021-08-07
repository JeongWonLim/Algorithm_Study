#include<iostream>
using namespace std;

int main(void)
{
	int E, S, M;
	int yE, yS, yM;
	
	cin >> E >> S >> M;

	yE = yS = yM = 1;
	
	int yCnt = 1;

	while (!( (((yCnt - E) % 15)==0) && (((yCnt - S) % 28) == 0) && (((yCnt - M) % 19) == 0)))
	{
	/*	yE = (yE + 1) % 16;
		yS = (yS + 1) % 29;
		yM = (yM + 1) % 20;

		if (yE == 0)
			yE++;
		if (yS == 0)
			yS++;
		if (yM == 0)
			yM++;
		yCnt++;*/

		yCnt++;
	}

	cout << yCnt << endl;

	return 0;
}