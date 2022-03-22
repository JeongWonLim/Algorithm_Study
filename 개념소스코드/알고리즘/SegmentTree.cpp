#include<iostream>
#include<vector>
#define INT_MAX 987654321
using namespace std;

//구간최소질의
class RMQ {
public:
	int n;
	vector<int> rangeMin;

	RMQ(const vector<int>& array) {
		n = array.size();
		rangeMin.resize(4 * n);
		init(array, 0, n - 1, 1);
	}

	//Top-Down 방식을 이용한 구간트리 생성
	int init(const vector<int>& array, int left, int right, int node) {
		
		if (left == right) return rangeMin[node] = array[left];
		
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid, right, node * 2 + 1);
		
		return rangeMin[node] = min(leftMin, rightMin);
	}

	//[left, right]까지 최소값을 구하는 질의
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {

		if (right < nodeLeft || nodeRight < left) return INT_MAX; // 찾으려는 구간과 검색 구간이 겹치지 않을 시
		if (left <= nodeLeft && nodeRight <= right) return rangeMin[node]; // 검색구간이 찾으려는 구간에 완전히 포함 시
		int mid = (nodeLeft + nodeRight) / 2;

		return min(query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid, nodeRight));
	}

	//인덱스 번호로 검색[0, n-1]
	int query(int left, int right) {
		query(left, right, 1, 0, n - 1);
	}
};

int main(void)
{

	return 0;
}