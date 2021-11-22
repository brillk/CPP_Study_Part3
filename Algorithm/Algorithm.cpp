﻿#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;


struct Vertex {

};

vector<Vertex> vertices;
vector<vector<int>> adjacent; //인접 행렬

void CreateGraph() {
	vertices.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
	
	adjacent[0][1] = 15;
	adjacent[0][3] = 35;

	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;

	adjacent[3][4] = 5;
	adjacent[5][4] = 5;


}


//찾은 다음 코스트를 계산하여 다 적게 쓰는 곳으로 이동
void Dijikstra(int here) {

	struct VertexCost {

		int vertex;
		int cost;
	};

	list<VertexCost> discovered; //발견 목록
	vector<int>	best(6, INT32_MAX); //각 정점별로 지금까지 발견한 최소거리
	vector<int> parent(6, -1);

	discovered.push_back(VertexCost{ here, 0 });
	best[here] = 0;
	parent[here] = here;

	while (discovered.empty() == false)
	{

		//제일 좋은 후보찾기
		list<VertexCost>::iterator bestIt;
		int bestCost = INT32_MAX;


		for (auto it = discovered.begin(); it != discovered.end(); it++) {

			const int cost = it->cost;
		
			//비교후 넘기기
			if (bestCost > cost)
			{
				bestCost = cost;
				bestIt = it;
			}
		}

		int cost = bestIt->cost;
		here = bestIt->vertex;
		discovered.erase(bestIt);

		//방문? 더 짧은 경로를 뒤늦게 찾았다면 스킵
		if (best[here] < cost)
			continue;

		//방문! 등록시키기

		for (int there =0; there < 6; there++)
		{
			//연결되지 않았으면 스킵,
			if (adjacent[here][there] == -1)
				continue;

			//더 좋은 경로를 과거에 찾았으면 스킵
			int nextCost = best[here] + adjacent[here][there];
			if (nextCost >= best[there])
				continue;

			
			discovered.push_back(VertexCost{ there, nextCost });
			best[there] = nextCost;
			parent[there] = here;
			
		}
	}

	int a = 0;
}

int main()
{
	CreateGraph();
	Dijikstra(0);
}