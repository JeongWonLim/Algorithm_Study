#include<iostream>
#include<vector>
#define INT_MAX 987654321
using namespace std;

//�����ּ�����
class RMQ {
public:
	int n;
	vector<int> rangeMin;

	RMQ(const vector<int>& array) {
		n = array.size();
		rangeMin.resize(4 * n);
		init(array, 0, n - 1, 1);
	}

	//Top-Down ����� �̿��� ����Ʈ�� ����
	int init(const vector<int>& array, int left, int right, int node) {
		
		if (left == right) return rangeMin[node] = array[left];
		
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid, right, node * 2 + 1);
		
		return rangeMin[node] = min(leftMin, rightMin);
	}

	//[left, right]���� �ּҰ��� ���ϴ� ����
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {

		if (right < nodeLeft || nodeRight < left) return INT_MAX; // ã������ ������ �˻� ������ ��ġ�� ���� ��
		if (left <= nodeLeft && nodeRight <= right) return rangeMin[node]; // �˻������� ã������ ������ ������ ���� ��
		int mid = (nodeLeft + nodeRight) / 2;

		return min(query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid, nodeRight));
	}

	//�ε��� ��ȣ�� �˻�[0, n-1]
	int query(int left, int right) {
		query(left, right, 1, 0, n - 1);
	}
};

int main(void)
{

	return 0;
}