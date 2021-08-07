#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;
int N, M, K;
int board[10][10];
int check[10][10] = { 0 };
int maxSum = -100000000;
int tot = 0;
vector<int> tempSum;

bool rangeCheck(int i, int j)
{
	if ((i< 0) || (i >= N))
		return false;
	if ((j< 0) || (j >= M))
		return false;

	return true;
}

void swap(int i, int j, int mark)
{
	if (rangeCheck(i - 1, j))
		check[i - 1][j] += mark;
	
	if (rangeCheck(i+1, j))
		check[i + 1][j] += mark;

	if (rangeCheck(i, j - 1))
		check[i][j - 1] += mark;

	if (rangeCheck(i, j + 1))
		check[i][j + 1] += mark;

	if (rangeCheck(i, j))
		check[i][j] += mark;
}

void findMaxSum()
{
	if (tempSum.size() == K)
	{
		maxSum = max(maxSum, tot);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!(check[i][j] > 0))
			{
				swap(i, j, 1);
				tempSum.emplace_back(board[i][j]);
				tot += board[i][j];
				findMaxSum();
				tot -= board[i][j];
				tempSum.pop_back();
				swap(i, j, -1);
			}
		}
	}
}

int main(void)
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	findMaxSum();
	cout << maxSum;
	return 0;
}