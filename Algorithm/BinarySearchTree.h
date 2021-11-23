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
//1. ��� ������ ���� �ƴϸ� ��
//2. root�� ��		
//3. LEAF(LIF)�� ��
//4. ���� ����� �ڽ��� ���̴� / �ڽ� ���� ������ �� ����
//5. �� ���κ��� ~ �������� ���� ��ε��� ��� ���� ���� ��
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

