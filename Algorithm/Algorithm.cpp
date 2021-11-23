#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include "BinarySearchTree.h"

// 오늘의 주제 : 이진 탐색 트리

//   [20]
// [10]   [30]
//      [25]  [40]
//        [26]  [50]
int main()
{
	BinarySearchTree bst;

	bst.Insert(30);
	bst.Insert(10);
	bst.Insert(20);
	bst.Insert(25);
	bst.Insert(26);
	bst.Insert(40);
	bst.Insert(50);

	bst.Delete(20);
	bst.Delete(26);

	bst.Print();

}