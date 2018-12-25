#ifndef TABLE_H
#define TABLE_H
#include <tree.h>
#include <data.h>

/*Big storage*/
class Table
{
	std::vector<Data> elem_;

public:
	Table();
	Table(std::vector<std::pair<int32_t, std::string>>& dict);
	~Table();
	


}

//swap - change places of elements - not needed, it's needed only to keep data;

#endif // TABLE_H