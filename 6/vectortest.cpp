
#include "vectortest.h"

std::ostream& operator << (
	std::ostream& stream, 
	const std::vector< std::string > & strs)
{
	for(auto it = strs.cbegin(); it != strs.cend(); ++it)
	{
		if(it != strs.cbegin())
			stream << ", ";
		stream << *it;
	}
	return stream;
}

#if 1
void vectortest::sort(std::vector<std::string> & v)
{
	for(size_t j = 0; j < v.size(); ++j)
		for(size_t i = 0; i < j; ++i)
		{
			if(v[i] > v[j])
			{
				std::swap(v[i], v[j]);
			}
		}
}
#endif
#if 0
void vectortest::sort(std::vector<std::string> & v)
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
#if 0
void vectortest::sort(std::vector<std::string> & v)
{
	for(size_t j = 0; j < v.size(); ++j)
		for(size_t i = 0; i < j; ++i)
		{
			if(v[i] > v[j])
			{
				std::string s = v[i];
				v[i] = v[j];
				v[j] = s;
			}
		}
}
#endif
#if 0
void vectortest::sort(std::vector<std::string> & v)
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
