#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
#include <windows.h>
using namespace std;

//오늘의 주제 : 동적 계획법(DP)

//ENCHANT

//강화 되는 횟수 1, 2, 3
//1 - 2 - 3 - ..9
//1 - 3 - 6 - 9
//1 - 3 - 4

int N;
int cache[100];

int Enchant(int num)
{
	//기저 사례
	if (num > N)
		return 0;
	if (num == N)
		return 1;

	//캐시 확인
	int& ret = cache[num];
	if (ret != -1)
		return ret;


	//적용
	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);
	
}


int main()
{
	N = 4;
	//4강 까지 강화되는 경우의 수 
	memset(cache, -1, sizeof(cache));

	int ret = Enchant(0);
	cout << ret << endl;
}