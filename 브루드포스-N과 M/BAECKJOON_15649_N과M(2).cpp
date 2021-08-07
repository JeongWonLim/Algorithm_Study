#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
int check[9] = { 0,1,1,1,1,1,1,1,1 };
int N, M;

void su(int start)
{
	if (M == arr.size())
	{
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i <= N; i++)
	{
		if (check[i] == 1)
		{
			check[i] = 0;
			arr.emplace_back(i);
			su(i+1);
			check[i] = 1;
			arr.pop_back();
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	su(1);
	return 0;
}