
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm> // for min
#include <functional>

template<typename C = std::less<std::string>>
std::map<std::string, unsigned int, C> frequencytable(
	const std::vector<std::string> & text)
{
	std::map<std::string, unsigned int, C> table;
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

struct case_insensitive
{
	bool operator() (const std::string& s1, const std::string& s2) const
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
};

struct case_insensitive_hash
{
	size_t operator() (const std::string& s) const
	{
		std::string cs = s;
		std::transform(cs.begin(), cs.end(), cs.begin(), ::tolower);
		std::hash<std::string> hashfun;
		return hashfun(cs);
	}
};

struct case_insensitive_equality
{
	bool operator() (const std::string& s1, const std::string& s2) const
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
	}
};

template<
	typename Hash = std::hash<std::string>,
	typename Pred = std::equal_to<std::string> >
std::unordered_map<std::string, unsigned int, Hash, Pred>
hashed_frequencytable(std::vector<std::string> text)
{
	std::unordered_map<std::string, unsigned int, Hash, Pred> table;
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

int main( int argc, char* argv [] )
{
	std::vector<std::string> text = { 
		{ "AA", "aA", "Aa", "this", "THIS", "Aa" } };
	auto table = frequencytable<case_insensitive>(text);
	std::cout << table;
	case_insensitive c;
	std::cout << c("a", "A") << c("a", "b") << c("A", "b") << "\n";
	case_insensitive_hash h;
	std::cout << h("xxx") << " " << h("XXX") << "\n";
	std::cout << h("Abc") << " " << h("abC") << "\n";
	
	case_insensitive_equality e;
	std::cout << e("xxx", "XXX") << "\n";
	
	auto table2 = hashed_frequencytable<
		case_insensitive_hash, case_insensitive_equality>
		(text);
	std::cout << table2;
	
	return 0;
}
