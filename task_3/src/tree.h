#ifndef TREE_H
#define TREE_H
#include <data.h>

Class Tree
{
	Tree* left_;
	Tree* right_;
	Data data_;

public:
	Tree(Data data);
	Tree (Tree left, Tree right);
	~Tree() = default;
	bool Leaf();

	void Gen_Codes_Root();
	void Gen_Codes(bool add);

	std::vector<bool> Get_Code(std::string symbol);

}

#endif // TREE_H