#include <cstdint>
#include <iostream>
#include "cell.h"

Cells::Cells() = Cells::Cells(1, 1, true);

Cells::Cells(int32_t nn, int32_t mm, bool current = false){
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

Cells::~Cells()
{
	delete[] state;
	state = NULL;
}

Cells::Cells (const field& A)
{
	n = A.n;
	m = A.m;
	state = new int32_t[n * m];
	for(int32_t i = 0; i < n*m; ++i) {
		state[i] = A.state[i]; 
	}
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
	state[i * m + j] = val;
}

Cells& Cells::operator = (const cells& A)
{
	if(this != &A) {
		n = A.n;
		m = A.m;
		delete[] state;
		state = new int32_t[n * m];
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

	for (k = i-1; k<=i+1; k++){
		for (l = j-1; l <=j+1; l++){
			if ((k != i) && (l != j)){
				if (get_st(k,l)){
					++ alive_counter;
				}
			}
		}
	}
	return alive_counter;
}

Cells Cells::next_gen() const
{
	int32_t count = 0;
	Cells next;
	next.n = n;
	next.m = m;
	next.state = new bool [n*m];
	for(int32_t i = 0; i < n, i++){
		for(int32_t j = 0; j < m; j++){
			count = alive_near (i,j);
			if(this.get_st(i, j)){
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
	return Field(next);
}