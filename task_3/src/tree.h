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
	Tree(std::pair<int32_t, std::string> pair)
	Tree (Tree left, Tree right);
	~Tree() = default;
	bool Leaf();

	void Gen_Codes_Root();
	void Gen_Codes(bool add);

	std::vector<bool> Get_Code(std::string symbol);
	Tree Create_Tree(std::vector<std::pair<int32_t, std::string>>& dict);
	Tree_Compare (Tree* first, Tree* second);
	void Code2table (std::vector<Data>& table);
	std::string Get_Symbol(std::vector<bool> code);

};

#endif // TREE_H