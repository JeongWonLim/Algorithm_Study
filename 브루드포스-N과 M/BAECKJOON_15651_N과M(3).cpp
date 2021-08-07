#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
int check[9] = { 0,1,1,1,1,1,1,1,1 };
int N, M;

void su()
{
	if (M == arr.size())
	{
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		arr.emplace_back(i);
		su();
		arr.pop_back();
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	su();
	return 0;
}