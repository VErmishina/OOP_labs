#ifndef DATA_H
#define DATA_H
#include <string>
#include <vector>
#include <stdint>
#include <tree.h>

Class Data
{
	std::string symbol_;
	uint32_t frequency_;
	std::vector<bool> code_;

public:
	Data();
	Data(std::string symbol, uint32_t frequency, std::vector<bool> code);
	~Data() = default;

	std::string get_s() const;
	uint32_t get_fr() const;
	std::vector<bool> get_code() const;

	void set_s(const std::string& symbol);
	void set_fr(const uint32_t frequency);
	void set_code(const std::vector<bool>& code);

	friend Tree;

};

#endif // DATA_H