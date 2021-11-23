#pragma once

//     [10]
//	 [5] [20]
//	       [30] 	

enum class Color
{
	Red = 0,
	Black =1,
};

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int		key = {};
	Color	color = Color::Black;
};


//red-black tree
//1. 모든 노드들은 레드 아니면 블랙
//2. root는 블랙		
//3. LEAF(LIF)는 블랙
//4. 레드 노드의 자식은 블랙이다 / 자식 노드는 레드일 수 없다
//5. 각 노드로부터 ~ 리프까지 가는 경로들은 모두 같은 수의 블랙
class BinarySearchTree
{
public:

	BinarySearchTree();
	~BinarySearchTree();

	void	Print() { Print(_root, 10, 0); }
	void	Print(Node* node, int x, int y);
	

	Node* Search(Node* node, int key);


	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node);

	void	Insert(int key);
	void	InsertFixup(Node* node);

	void	Delete(int key);
	void	Delete(Node* node);
	void	Replace(Node* u, Node* v);

	//Red-Black Tree
	void LeftRotate(Node* node);
	void RightRotate(Node* node);

private:
	Node* _root = nullptr;
	Node* _nil = nullptr;
};

