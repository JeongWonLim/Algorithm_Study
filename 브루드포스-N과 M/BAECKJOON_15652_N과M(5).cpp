#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int M, N;
vector<int> Numbers;
vector<int> NumGroup;
int check[10001];

void up()
{
	if (NumGroup.size() == N)
	{
		for (int i = 0; i < NumGroup.size(); i++)
			cout << NumGroup[i] << ' ';
		cout << '\n';
	}

	for (int i = 0; i < Numbers.size(); i++)
	{
		if (check[Numbers[i]] == 1)
		{
			check[Numbers[i]] = 0;
			NumGroup.emplace_back(Numbers[i]);
			up();
			check[Numbers[i]] = 1;
			NumGroup.pop_back();
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> M >> N;

	for (int i = 0; i < 10001; i++)
		check[i] = 0;

	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		check[a] = 1;
		Numbers.emplace_back(a);
	}

	sort(Numbers.begin(), Numbers.end());
	
	up();
	return 0;
}