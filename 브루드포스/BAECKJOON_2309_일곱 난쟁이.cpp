#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	vector<int> man;
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		int height;
		cin >> height;
		man.emplace_back(height);
		sum += height;
	}
	
	sort(man.begin(), man.end());

	for (vector<int>::iterator iter1 = man.begin(); iter1 != man.end(); iter1++)
	{
		for (vector<int>::iterator iter2 = man.begin(); iter2 != man.end(); iter2++)
		{
			if ((iter1 != iter2) && (sum - (*iter1 + *iter2) == 100))
			{
				
				for (auto t1 = man.begin(); t1 != man.end(); t1++)
				{
					if ((t1 != iter1) && (t1 != iter2))
						cout << *t1 << endl;
				}

				return 0;
			}
		}
	}

	
	return 0;
}