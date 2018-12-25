#include <cstdint>
#include <iostream>
#include "cell.h"

Cells::Cells():  Cells::Cells(1, 1, true) {};

Cells::Cells(int32_t nn, int32_t mm, bool current) {
	if(n < 1) {
		n = 1;
	}
	if(m < 1) {
		m = 1;
	}
	state = new bool[n*m];
	for(int32_t i = 0; i < n * m; i++) {
		if(current == true) {
			state[i] = current;
		} else {
			state[i] = false;
		}
	}
}

Cells::Cells(const Cells& A)
{
	n = A.n;
	m = A.m;
	state = new bool[n * m];
	for(int32_t i = 0; i < n*m; ++i) {
		state[i] = A.state[i]; 
	}
}

Cells::~Cells()
{
	delete[] state;
	state = NULL;
}

int32_t Cells::get_n() {
	return n;
}
int32_t Cells::get_m() {
	return m;
}

bool Cells::get_st(int32_t i, int32_t j)  const
{
	if(i < 0) {
		i += n;
	}
	if(i >= n) {
	i -= n;
	}
	if(j < 0) {
		j += m;
	}
	if(j >= m) {
		j -= m;
	}
	return state[i * m + j];	
}

void Cells::give_st (int32_t i, int32_t j, bool value)
{
	state[i * m + j] = value;
}

Cells& Cells::operator = (const Cells& A)
{
	if(this != &A) {
		n = A.n;
		m = A.m;
		delete[] state;
		state = new bool[n * m];
		for(int32_t i = 0; i < n; i++) {
			for(int32_t j = 0; j < m; j++) {
				this->give_st(i, j, A.get_st(i, j));
			}
		}		
	}
	return *this;
}

int32_t Cells::alive_near (int32_t i, int32_t j)
{
	int32_t alive_counter = 0;

	for (int32_t k = i-1; k <= i+1; k++){
		for (int32_t l = j-1; l <=j+1; l++){
			if ((k != i) || (l != j)){
				if (this -> get_st(k,l)){
					alive_counter++ ;
				}
			}
		}
	}
	return alive_counter;
}

Cells Cells::next_gen()
{
	int32_t count = 0;
	Cells next;
	next.n = n;
	next.m = m;
	next.state = new bool [n*m];
	for(int32_t i = 0; i < n; i++){
		for(int32_t j = 0; j < m; j++){
			count = this -> alive_near (i,j);
			if(this -> get_st(i, j)){
				if (count == 2 || count == 3){
					next.give_st(i, j, true);
				} else{
					next.give_st(i, j, false);
				}
			} else {
				if (count == 3){
					next.give_st(i, j, true);
				} else{
					next.give_st(i, j, false);
				}
			}
		}
	}
	return Cells(next);
}

std::ifstream& operator >> (std::ifstream& input_file, Cells& A)
{
	input_file >> A.n >> A.m;
	input_file.get();
	delete[] A.state;
	A.state = new bool[A.n * A.m];
	char symbol;
	for (int32_t i = 0; i < A.n; i++){
		for (int32_t j = 0; j <A.m; j++){
			symbol = input_file.get();
			if (symbol ==  '*'){
				A.give_st(i, j, true);
			}else {
				A.give_st(i, j, false);
			}
		}
		input_file.get();
	}
	return input_file;
}

void Draw(sf::RenderWindow& window, Cells& A)
{
	sf::RectangleShape* blocks = new
		sf::RectangleShape[A.n * A.m];
	int32_t position = 0;
	int32_t c_width = window_width / A.m;
	int32_t height_h = window_height / A.n;
	for(int32_t i = 0; i < A.n; ++i) {
		for(int32_t j = 0; j < A.m; ++j) {
			position = i * A.m + j;
			blocks[position].setSize(sf::Vector2f(c_width,
											   height_h));
			blocks[position].setPosition(c_width * j, height_h * i);
			if(A.get_st(i, j)) {
				blocks[position].setFillColor(sf::Color (0, 204, 102, 255));
			} else {
				blocks[position].setFillColor(sf::Color (125, 125, 125, 255));
			}
			window.draw(blocks[position]);
		}
	}
	delete[] blocks;
}