#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
using namespace std;

//그래프/ 트리 응용
//오늘의 주제 : 최소 스패닝 트리 Minimum Spanning Tree


// 상호 배타적 집합 Disjoint Set
// -> 유니온-파인드 Union-Find

void NewGame() {

	struct User
	{
		int teamId;
		//TODO
	};

	//TODO
	vector<User> users;
	for (int i = 0; i < 1000; i++)
	{
		users.push_back(User{ i });
	}

	//팀 동맹
	//user 1 <-> user 5
	users[5].teamId = users[1].teamId;

	//teamId = 1인 팀과 teamId = 2인 팀이 통합

	for (User& user : users)
	{
		if (user.teamId == 1)
			user.teamId = 2;
	}

	//찾기 연산 0(1)
	//합치기 연산 0(N) 


}


//트리 구조를 이용한 상호 배타적 집합의 표현 
//[0][1][2][3]

struct Node
{
	Node* leader;
};

//1과 3이 대장
//[1]	[3]
//[2]	[4][5]
//		[0]


//시간 복잡도 0 (Ackermann(n)) = 0(1)
class NaiveDisjointSet
{

public:
	NaiveDisjointSet(int n) : _parent(n)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	//마 니 대장이 뉘고?
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return Find(_parent[u]);
	}

	//u와 v를 합친다 (일단 u가 v밑으로)
	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		//rank[u] <= rank[v] 보장됨
		_parent[u] = v;
	
	}

private:
	vector<int> _parent;
	
};



//트리가 한쪽으로 기우는 문제를 해결
//트리를 합칠때, 항상 [높이가 낮은 트리를] [높이가 높은 트리] 밑으로 넣어주자
//Union-By-Rand 랭크에 의한 합치기 최적화


// 시간 복잡도 O(Ackermann(n)) = O(1)
class DisjointSet
{
public:
	DisjointSet(int n) : _parent(n), _rank(n, 1)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	// 조직 폭력배 구조?
	// [1]		[3]
	// [2]	 [4][5][0]
	// 		    

	// 니 대장이 누구니?
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		//_parent[u] = Find(_parent[u]);
		//return _parent[u];

		return _parent[u] = Find(_parent[u]);
	}

	// u와 v를 합친다
	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		if (_rank[u] > _rank[v])
			swap(u, v);

		// rank[u] <= rank[v] 보장됨
		_parent[u] = v;

		if (_rank[u] == _rank[v])
			_rank[v]++;
	}

private:
	vector<int> _parent;
	vector<int> _rank;
};

int main()
{
	DisjointSet teams(1000);

	teams.Merge(10, 1);
	int teamId = teams.Find(1);
	int teamId2 = teams.Find(10);

	teams.Merge(3, 2);
	int teamId3 = teams.Find(3);
	int teamId4 = teams.Find(2);

	teams.Merge(1, 3);
	int teamId5 = teams.Find(1);
	int teamId6 = teams.Find(3);

}