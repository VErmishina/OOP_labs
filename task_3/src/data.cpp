#include <data.h>

Data::Data: Data::Data(0, 0, 0);

Data::Data(std::string symbol, uint32_t frequency, std::vector<bool> code)
{
	symbol_ = symbol;
	frequency_ = frequency;
	code_ = code;
}

Data::Data(pair<int32_t, std::string> mypair)
{
	symbol_ = mypair.second;
	frequency_ = mypair.first;
	code_ = 0;
}

std::string Data::get_s() const
{
	return symbol_;
}

uint32_t Data::get_fr() const
{
	return frequency_;
}

std::vector<bool> Data::get_code() const
{
	return code_;
}

void set_s(const std::string& symbol)
{
	symbol_ = symbol;
}

void set_fr(const uint32_t frequensy)
{
	frequensy_ = frequency;
}

void set_code(const std::vector<bool>& code)
{
	code_ = code;
}

