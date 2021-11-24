#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
using namespace std;

// 오늘의 주제 : 정렬

//코딩면접 시험에 은근히 나온다고 한다

// 1. 버블 정렬 (Bubble Sort)

// 1대1로 비교후 큰건 뒤로 작은건 앞으로 뒤바뀐다
// 한번 루프를 돌면 제일 큰 값이 맨 뒤에 있기 떄문에
// 다음 루프를 돌때에는 그 값을 포함하지 않고 비교하며 또 정렬한다
// 효율이 좋지 않다

void BubbleSort(vector<int>& v)
{
	const int n = (int)v.size();

	//시간 복잡도 N-1 + N-2
	//등차수열의 합 = N * (N-1) /2
	//0(N^2) ㅈㄴ 느림
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - 1 - i); j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}


// 2. 선택 정렬 (Selection Sort)
// 직관적이다
// 한번에 사악 훝어보고 가장 작은 값을 맨 앞에 놓는다
// 앞의 값이 정해졌으니 남은 값들을 같은 식으로 훝어보고
// 다시 정렬한다
void SelectionSort(vector<int> & v)
{
	const int n = (int)v.size();

	//시간 복잡도 N-1 + N-2
	//등차수열의 합 = N * (N-1) /2
	//0(N^2) 버블보단 조금 더 성능이 낫다

	for (int i = 0; i < n - 1; i++)
	{
		//한번 돌면서 가장 좋았던 애가 몇번째 인덱스에 있는지 
		int bestIdx = i;
		
		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[bestIdx])
				bestIdx = j;
		}

		//교환
		int temp = v[i];
		v[i] = v[bestIdx];
		v[bestIdx] = temp;
	}
}


// 3. 삽입 정렬 (Insertion Sort)
// 면접 시험에 자주 나옴
// 값이 랜덤으로 정렬되어 있으면 맨 앞의 값을 
// 또 하나의 통로에 하나씩 집어 넣는다 
// 하나씩 물어보면서 복사를 하고 크기에 따라 재정렬된다


void InsertSort(vector<int>& v)
{
	const int n = (int)v.size();

	//0(N^2) 딱히 좋진 않다 그냥 위보다 약간 나은 정도?
	for (int i = 1; i < n; i++)
	{
		int insertData = v[i];

		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (v[j] > insertData)
				v[j + 1] = v[j];
			else
				break;
		}

		v[j + 1] = insertData;
	}
}

int main()
{
	vector<int> v{ 1,5,3,4,2 };
	std::sort(v.begin(), v.end());

	//BubbleSort(v);
	//SelectionSort(v);
	InsertSort(v);

}