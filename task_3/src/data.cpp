#include <data.h>

Data::Data()
{
	symbol_ = std::string;
	frequency_ = 0;
	code_ = std::vector<bool>;
}

Data::Data(std::string symbol, uint32_t frequency, std::vector<bool> code)
{
	symbol_ = symbol;
	frequency_ = frequency;
	code_ = code;
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

