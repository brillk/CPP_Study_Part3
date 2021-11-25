﻿#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
#include <windows.h>
using namespace std;

//오늘의 주제 : 동적 계획법(DP)

//TRIANGLE_PATH
// 0,0부터 시작해서 아래 혹은 아래우측으로 이동 가능
// 만나는 숫자를 모두 더함
// 더한 숫자가 최대가 되는 경로 

int N;
vector<vector<int>> board;
vector<vector<int>> cache;
vector<vector<int>> nextX;

int path(int y, int x)
{
	//기저 사항
	//if (y == N - 1)
	//	return board[y][x];
	if (y == N)
		return 0;

	//캐시 확인
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;


	//적용
	/*board[y][x] + path(y + 1, x);
	board[y][x] + path(y + 1, x + 1);	*/

	//경로기록
	{
		int nextBottom = path(y + 1, x);
		int nextBottomRight = path(y + 1, x+1);
		if (nextBottom > nextBottomRight)
			nextX[y][x] = x;
		else
			nextX[y][x] = x + 1;
	}


	//현재 값에서 다음에 들어가는 최대값을 비교해서 실행
	return ret = board[y][x] + max(path(y + 1, x), path(y + 1, x + 1));
}

int main()
{
	board = vector<vector<int>>
	{
		{6},
		{1, 2},
		{3, 7, 4},
		{9, 4, 1, 7},
		{2, 7, 5, 9, 4}
	};

	N = board.size();
	cache = vector<vector<int>>(N, vector<int>(N, -1));
	nextX = vector<vector<int>>(N, vector<int>(N));

	int ret = path(0, 0);
	cout << ret << endl; // 6 2 4 7 9 = 28


	//경로 만들기
	int y = 0;
	int x = 0;

	while (y < N)
	{
		cout << board[y][x] << "->";
		//6->2->4->7->9

		x = nextX[y][x];
		y++;
	}
}