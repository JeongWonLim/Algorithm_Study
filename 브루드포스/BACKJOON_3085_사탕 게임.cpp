#include<iostream>
using namespace std;

int N;
char board[50] [50] ;
int Candy = 1; // 최소 한개의 사탕은 먹을 수 있음.

void maxCandy()
{
	int cnt;
	for (int i = 0; i < N; i++)
	{
		//행
		cnt = 1;
		for (int j = 1; j < N; j++)
		{
			if (board[i][j - 1] != board[i][j])
			{
				cnt = 1;
			}
			else
				cnt++;
			if (Candy < cnt)
				Candy = cnt;
		}

		//열
		cnt = 1;
		for (int j = 1; j < N; j++)
		{
			if (board[j - 1][i] != board[j][i])
			{
				cnt = 1;
			}
			else
				cnt++;
			if (Candy < cnt)
				Candy = cnt;
		}
	}
}

int range(int x, int y)
{
	if ((0 <= x && x < N) && (0 <= y && y < N))
		return 1;

	return 0;
}

void swap(int x1, int y1, int x2, int y2)
{
	char temp;
	temp = board[x1][y1];
	board[x1][y1] = board[x2][y2];
	board[x2][y2] = temp;
}

void candyswap(int x, int y)
{
	if (range(x - 1, y))
	{
		swap(x, y, x - 1, y);
		maxCandy();
		swap(x, y, x - 1, y);
	}

	if (range(x + 1, y))
	{
		swap(x, y, x + 1, y);
		maxCandy();
		swap(x, y, x + 1, y);
	}

	if (range(x, y-1))
	{
		swap(x, y, x, y-1);
		maxCandy();
		swap(x, y, x, y - 1);
	}

	if (range(x, y+1))
	{
		swap(x, y, x, y +1);
		maxCandy();
		swap(x, y, x, y + 1);
	}

	
}


int main(void)
{
	cin >> N;
	
	//입력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
		

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			candyswap(i, j);
	}

	cout << Candy << endl;
	
	return 0;
}