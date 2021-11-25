﻿#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
#include <windows.h>
using namespace std;

//오늘의 주제 : 동적 계획법(DP)


//TIC-TAC-TOE

//[.][.][.]
//[.][0][.]
//[.][.][X]
	
int Hashkey(const vector<vector<char>>& board)
{
	int ret = 0;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			ret = ret * 3;

			if (board[y][x] == 'o')
				ret += 1;
			else if (board[y][x] == 'x')
				ret += 2;
		}
	}
	return ret;
}

vector<vector<char>> board;
int cache[19683];
enum
{
	DEFAULT = 2,
	WIN = 1,
	DRAW = 0,
	LOSE = -1
};

bool IsFinished(const vector<vector<char>>& board, char turn)
{
	//좌우 승리
	for (int i = 0; i < 3; i++)
		if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn)
			return true;

	
	//상하 승리
	for (int i = 0; i < 3; i++)
		if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn)
			return true;

	//대각선 승리
	if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn)
		return true;

	if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
		return true;

	return false;
}

int CanWin(vector<vector<char>>& board, char turn)
{
	//기저 사례 (예외 사항)
	//이미 이겼거나 졌거나 둘 수가 없을때
	if (IsFinished(board, 'o' + 'x' - turn))
		return LOSE;


	//캐시 확인
	//이중벡터? ㄴ 123123123 => 3^9 = 19683
	int key = Hashkey(board);
	int& ret = cache[key];
	if (ret != DEFAULT)
		return ret;


	//풀기
	// 
	int minValue = DEFAULT;
	//빈 좌표를 쓴다
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[y][x] != '.')
				continue;

			//착수
			board[y][x] = turn;

			//확인
			minValue = min(minValue, CanWin(board, 'o' + 'x' - turn));
		
			//상대방이 패배하는게 제일 좋은 케이스

			//취소 
			board[y][x] = '.';	
		}
	}

	if (minValue == DRAW || minValue == DEFAULT)
		return ret = DRAW;

	return ret = -minValue;
}

int main()
{
	board = vector<vector<char>>
	{
		{'o', 'o', 'x'},
		{'.', 'x', '.'},
		{'.', '.', 'x'}
	};



	for (int i = 0; i < 19683; i++)
		cache[i] = DEFAULT;

	int win = CanWin(board, 'o');

	switch (win)
	{
	case WIN:
		cout << "Win" << endl;
		break;
	case DRAW:
		cout << "DRAW" << endl;
		break;
	case LOSE:
		cout << "LOSE" << endl;
		break;
	}
	
}