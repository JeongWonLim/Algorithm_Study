#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(void)
{
	int nCnt;
	vector<int> divisiors;

	cin >> nCnt;

	for (int i = 0; i < nCnt; i++)
	{
		int divisior;
		cin >> divisior;

		divisiors.emplace_back(divisior);
	}

	int maxDivisor = *max_element(divisiors.begin(), divisiors.end()); //stl �ִ밪 ���ϱ�
	int minDivisor = *min_element(divisiors.begin(), divisiors.end()); //STL �ּҰ� ���ϱ�
	
	cout << maxDivisor * minDivisor;
	return 0;
}
