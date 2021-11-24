#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
using namespace std;

// 오늘의 주제 : 정렬

//힙 정렬
//우선순위 큐가 조건 때문에 작은 순서대로 정렬된 값을 꺼내준다
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;


	//시간 복잡도
	//0(N logN)
	for (int num : v)
		pq.push(num);

	v.clear();

	//0(N logN) 그래도 느리긴하다
	while (pq.empty() == false)
	{
		v.push_back(pq.top());
		pq.pop();

	}
}


//병합 정렬
//분할 정복 (Divide and Conquer)
//	분할 Divide 문제를 단순하게 분할
//	정복 COnquer 분할된 문제를 해결
//  결합 Combine 결과 취합후 마무리
//

// [3][k][7][2][j][4][8][9]		8개 * 1
// [3][k][7][2]		[j][4][8][9] 4개 * 2 
// [2][3] [7][k]		[4][8] [9][j] 2개 * 4 
// 
// [2][3][4][7][8][9][j][k]	 
// 분할되는 만큼 또 나눠서 할 수 있다
// 조립도 마찬가지다


//0(N logN)
void MergeResult(vector<int>& v, int left, int mid, int right)
{
	//[3][k][7][2]	[j][4][8][9]

	int leftIdx = left;
	int rightIdx = mid + 1;


	vector<int> temp;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] <= v[rightIdx])
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}

	//왼쪽이 먼저 끝났으면, 오른쪽 나머지 데이터 복사
	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	//오른쪽이 먼저 끝났으면, 왼쪽 나머지 데이터 복사
	else
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
		v[left + i] = temp[i];
}

void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(v, left, mid); //앞의 4개
	MergeSort(v, mid + 1, right); //뒤의 4개

	MergeResult(v, left, mid, right);
}

int main()
{
	vector<int> v;

	srand(time(0));

	for (int i = 0; i < 50; i++)
	{
		int randValue = rand() % 100;
		v.push_back(randValue);
	}

	//BubbleSort(v);
	//SelectionSort(v);
	//InsertSort(v);
	//HeapSort(v);

	MergeSort(v, 0, v.size() - 1);


}