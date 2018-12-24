#define GAME_H
#include <cstdint>
#include <fstream>
#include <SFML/Graphics.hpp>

const int32_t window_width = 1024;
const int32_t window_height = 768;

class Cells
{
	/*Game Field size*/
	int32_t n;
	int32_t m;

	/*Array of cells statement, true = alive, false = dead*/
	bool* statement;

public:
	Cells();
	Cells(int32_t nn, int32_t mm, bool current = false);
	~Cells();
	Cells(const Cells& A);
	int32_t get_n();
	int32_t get_m();
	bool get_st(int32_t i, int32_t j)  const;
	void give_st (int32_t i, int32_t j, bool value);
	Cells& operator = (const Cells& A);
	int32_t Cells::alive_near (int32_t i, int32_t j);
	Cells Cells::next_gen() const;




}

