#include <tree.h>

Tree::Tree(Data data)
{
	data_ = data;
	left_ = nullptr;
	right_ = nullptr;
}

Tree::Tree(std::pair<int32_t, std::string> pair)
{
	data_ = data;
	left_ = nullptr;
	right_ = nullptr;
}

Tree::Tree (Tree left, Tree right)
{
	data_.symbol_ = left.data_.symbol_ + right.data_.symbol_;
	data_.frequency_ = left.data_.frequency_ + right.data_.frequency_;
	data_.code_ = std::vector<bool>();
	left_ = &left;
	right_ = &right;
}

bool Tree::Leaf()
{
	return (left_ == nullptr && right_ == nullptr){
}

void Tree::Gen_Code (bool add)
{
	data_.code_.insert(data_.code_.begin(), add);
	left_ -> step(0);
	right_ -> step(1);

}
void Tree::Gen_Code_Root()
{
	left_ -> step(0);
	right_ -> step(1);
}

std::vector<bool> Tree::Get_Code(std::string& symb)
{
	if (symb.lenght() > 1){
		std::cout << "Not a symbol " << std::endl;
	} else{
		if (this -> Leaf && data_.symbol_ == symb){
			return data_.code_;
		} else{
			left_ -> Get_Code(symb);
			right_ -> Get_Code(symb);
		}
	}
}

