
#include "listtest.h"

std::ostream& operator << (
	std::ostream& stream,
	const std::list< std::string > & strs)
{
	for(auto it = strs.cbegin(); it != strs.cend(); ++it)
	{
		if(it != strs.cbegin())
			stream << ", ";
		stream << *it;
	}
	return stream;
} 

#if 0
void listtest::sort(std::list<std::string> & v)
{
	for(auto q = v.begin(); q != v.end(); ++q)
		for(auto p = v.begin(); p != q; ++p)
		{
			if(*p > *q)
			{
				std::swap(*p, *q);
			}
		}
}
#endif

#if 1
void listtest::sort(std::list<std::string> & v)
{
	for(auto q = v.begin(); q != v.end(); ++q)
		for(auto p = v.begin(); p != q; ++p)
		{
			if(*p > *q)
			{
				std::string s = *p;
				*p = *q;
				*q = s;
			}
		}
}
#endif
