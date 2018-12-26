#include <tree.h>

Tree::Tree(Data() data)
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
	return (left_ == nullptr && right_ == nullptr);
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

Tree Tree::Create_Tree(std::vector<std::pair<int32_t, std::string>>& dict)
{
	std::vector<Tree>> pain;  
	for(auto it = dict.begin(); it != dict.end(); ++it){
		Tree(it) temp_tree;
		pain.push_back(temp_tree);
		temp_tree.~Tree ;  
	}
	pain.erase(pain.begin());	/*erase auto-created element*/
	std::sort(pain.begin(),pain.end()); /*Will solve correct or will need to compare trees?*/

	while (pain.size <1){
		Tree(pain[0], pain[1]) temp_tree;
		pain.push_back(temp_pair);
		pain.erase(pain.begin());
		pain.erase(pain.begin());
		std::sort(pain.begin(), pain.end(), Tree_Compare);
	}
	return pain[0];  /*It's root of our tree*/
}

bool Tree::Tree_Compare (Tree* first, Tree* second)
{
	if (first->data_.frequency_ == second->data_.frequency_){
		return first->data_.symbol_ < second->data_.symbol_
	} else{
		return first->data_.frequency_ < second->data_.frequency_;
	}
}

void Tree::Code2table (std::vector<Data>& table)
{
	for (uint32_t i = 0; i < table.size; ++i){
		table[i].code_ = Get_Code(table[i].symbol_);
	}
}

std::string Get_Symbol(std::vector<bool> code)
{
	if (this -> Leaf && data_.code_ == code){
			return data_.symbol_;
	}else {
		left_ -> Get_Symbol(code);
		right_ -> Get_Symbol(code);
	}

}