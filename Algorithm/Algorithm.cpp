#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include "BinarySearchTree.h"
#include <thread>
// 오늘의 주제 : 이진 탐색 트리

//트리의 균형을 맞추는 "레드 블랙 트리"

//   [20]
// [10]   [30]
//      [25]  [40]
//        [26]  [50]
int main()
{
	BinarySearchTree bst;

	bst.Insert(30);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(10);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(20);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(25);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Delete(20);
	bst.Print();
	this_thread::sleep_for(1s);
	
	bst.Delete(10);
	bst.Print();
	this_thread::sleep_for(1s);
	

}