#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int M, N;
vector<int> Numbers;
vector<int> NumGroup;

void up()
{
	if (NumGroup.size() == N)
	{
		for (int i = 0; i < NumGroup.size(); i++)
			cout << NumGroup[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < Numbers.size(); i++)
	{
		NumGroup.emplace_back(Numbers[i]);
		up();
		NumGroup.pop_back();
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		Numbers.emplace_back(a);
	}

	sort(Numbers.begin(), Numbers.end());

	up();
	return 0;
}