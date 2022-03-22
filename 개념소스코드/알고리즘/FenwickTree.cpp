#include<iostream>
#include<vector>

using namespace std;

class Fenwick
{
public:
	Fenwick(int n) : Tree(n + 1) {}

	int sum(int pos)
	{
		pos++;
		int ret = 0;

		while (pos > 0)
		{
			ret += Tree[pos];
			pos -= (pos & -pos);
		}

		return ret;
	}

	void add(int pos, int val)
	{
		pos++;
		while (pos < Tree.size())
		{
			Tree[pos] += val;
			pos += (pos & -pos);
		}
	}
	vector<int> Tree;
};

int main(void)
{
	Fenwick Fen(10);

	int arr[10] = { 5,3,1,0,9,3,-2,6,-5,2 };
	for (int i = 0; i < 10; i++)
		Fen.add(i, arr[i]);

	for (int i = 0; i < 11; i++)
		cout << Fen.Tree[i] << ' ';

	cout << endl;

	cout << Fen.sum(8) - Fen.sum(2);
	return 0;
}