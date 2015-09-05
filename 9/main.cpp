
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm> // for min
#include <functional>

bool mapcmp (const std::string& s1, const std::string& s2)
{
	size_t l1 = s1.size();
	size_t l2 = s2.size();
	for(size_t i = 0; i < std::min(l1, l2); i++)
	{
		if(::tolower(s1[i]) < ::tolower(s2[i]))
			return true;
		if(::tolower(s1[i]) > ::tolower(s2[i]))
			return false;
	}
	return l1 < l2;
}

template<typename D>
std::map<std::string, unsigned int, D> frequencytable(
	const std::vector<std::string> & text, const D& cmp)
// how could one know that cmp must be a lambda?
{
	std::map<std::string, unsigned int, D> table { cmp };
	for(const auto& w : text)
		table[w]++;
	
	return table;
}

std::map<std::string, unsigned int,
// ugly... do we have to write down that type explicitly?
bool (*) (const std::string& s1, const std::string& s2)
> frequencytable_ptr(
	const std::vector<std::string> & text,
	bool (*cmp) (const std::string& s1, const std::string& s2)
	)
// how could one know that cmp must be a function pointer?
{
	std::map<std::string, unsigned int,
		bool (*) (const std::string& s1, const std::string& s2)
		> table { cmp };
	for(const auto& w : text)
		table[w]++;
	
	return table;
}

template<typename C>
std::ostream& operator << (
	std::ostream& stream,
	const std::map<std::string, unsigned int, C> & freq)
{
	for(const auto& p : freq)
		stream << p.first << " => " << p.second << "\n";
	return stream;
}

template<
	typename Hash = std::hash<std::string>,
	typename Pred = std::equal_to<std::string> >
std::unordered_map<std::string, unsigned int, Hash, Pred>
hashed_frequencytable(std::vector<std::string> text,
	const Hash& hash, const Pred& pred)
{
	std::unordered_map<std::string, unsigned int, Hash, Pred>
		table { 2, hash, pred };
	for(const auto& w : text)
		table[w]++;
	
	return table;
}

template<
	typename Hash = std::hash<std::string>,
	typename Pred = std::equal_to<std::string> >
std::ostream& operator << (
	std::ostream& stream,
	const std::unordered_map<
		std::string, unsigned int, Hash, Pred>
		& freq)
{
	for(const auto& p : freq)
		stream << p.first << " => " << p.second << "\n";
	return stream;
}

template<typename A, typename B>
std::ostream& operator << (
	std::ostream& stream,
	const std::pair<A, B> & pr)
{
	stream << "<" << pr.first << ", " << pr.second << ">";
	return stream;
}

template<typename A, typename C>
std::pair<A, unsigned int> most_frequent(
	const std::map<A, unsigned int, C> & mp)
{
	return *mp.rbegin();
}

int main( int argc, char* argv [] )
{
	std::vector<std::string> text = { 
		{ "AA", "aA", "Aa", "this", "THIS", "Aa" } };
	
	auto cmp = [] (const std::string& s1, const std::string& s2)
	{
		size_t l1 = s1.size();
		size_t l2 = s2.size();
		for(size_t i = 0; i < std::min(l1, l2); i++)
		{
			if(::tolower(s1[i]) < ::tolower(s2[i]))
				return true;
			if(::tolower(s1[i]) > ::tolower(s2[i]))
				return false;
		}
		return l1 < l2;
	};
	auto table = frequencytable<decltype(cmp)>(text, cmp);
	std::cout << table;
	
	auto hash = [] (const std::string& s)
	{
		std::string cs = s;
		std::transform(cs.begin(), cs.end(), cs.begin(), ::tolower);
		std::hash<std::string> hashfun;
		return hashfun(cs);
	};
	auto hash_eq = [] (const std::string& s1, const std::string& s2)
	{
		size_t l1 = s1.size();
		size_t l2 = s2.size();
		if(l1 != l2)
			return false;
		for(size_t i = 0; i < std::min(l1, l2); i++)
		{
			if(::tolower(s1[i]) != ::tolower(s2[i]))
				return false;
		}
		return true;
	};
	auto table2 = hashed_frequencytable<
		decltype(hash), decltype(hash_eq)>(text, hash, hash_eq);
	std::cout << table2;
	
	auto table3 = frequencytable_ptr(text, mapcmp);
	std::cout << table3;
	
	std::cout << most_frequent<std::string, decltype(cmp)>(table);
	std::cout << "\n";
	return 0;
}
