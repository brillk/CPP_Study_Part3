#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
#include <windows.h>
using namespace std;

//오늘의 주제 : 동적 계획법(DP)
//LIS Longest Increasing Sequence

//Seq :  1 9 3 5 6
//부분 수열 : 일부(0개 이상) 숫자를 지우고 남은 수열
//ex) 1 3 5  -  1 9 5
//순 증가 부분 수열 - 첫 값부터 오름차순으로 커지는 것
//ex) 1 3 5  맞음
//ex) 1 9 5  틀림

//LIS : 제일 긴 [순 증가 부분 수열] 
// 1 3 5 6 = 9를 뺸 가장 길이가 긴 부분 수열 4짜리 

int cache[100];
vector<int> seq; 

int LIS(int pos)
{
	//기저 사항 
	

	//캐시 확인
	int& ret = cache[pos];
	if (ret != -1)
		return ret;
	//구하기
	//Seq :  1 9 3 5 6
	//1 9  
	//1 3
	//1 5
	//1 6 
	// 
	// 1이 모든 값보다 작으니까 다음에 올 값은 이렇게 정해져 있는데
	// 1 9 다음에 숫자가 다 작으니 이것의 크기는 2다
	// 1 3 5 6 시작하는 인덱스가 점차 커지는 형태면 살을 붙인다 사이즈는 4
	// 1 5 6 사이즈는 3
	// 1 6 사이즈는 2 
	// 시작하는 인덱스부터 시작해 전의 값보다 커야 한다 
	// 
	//최소 seq[pos]은 있으니 1부터 시작

	ret = 1;

	//구하기
	for (int next = pos + 1; next < seq.size(); next++)
		if (seq[pos] < seq[next]) 
			ret = max(ret, 1 + LIS(next));
	return ret;		
}

int main()
{
	::memset(cache, -1, sizeof(cache));
	seq = vector<int>{ 10, 1, 9, 2, 5, 6 };

	//모든 아이를 한번 씩 순회해야한다
	int ret = 0;
	for (int pos = 0; pos < seq.size(); pos++)
		ret = max(ret, LIS(pos));
}