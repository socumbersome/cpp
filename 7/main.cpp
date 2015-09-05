
#include <iostream>
#include <vector>
#include <list>
#include "rational.h"

struct xx;
std::ostream& 
operator << ( std::ostream& stream, const xx & x);

struct xx
{
	int val;
	static unsigned int copied;
	static unsigned int moved;
	
	explicit xx(int val) : val { val }
	{ }
	
	#if 1
	xx(xx&& x) noexcept
		: val { x.val }
	{
		std::cout << "move constr " << *this << "\n";
		++moved;
	}
	#endif
	
	#if 1
	xx(const xx& x)
		: val { x.val }
	{
		std::cout << "copy const " << *this << "\n";
		++copied;
	}
	#endif
	
	//xx(xx& x) = delete; // gives an error!
	//xx(const & x) = delete;
};

std::ostream& 
operator << ( std::ostream& stream, const xx & x)
{
	return stream << "[xx: " << x.val << "]";
}

unsigned int xx::copied = 0;
unsigned int xx::moved = 0;

void pushalot_vec()
{
	std::vector<xx> v;
	v.reserve(50);
	for(int i = 0; i < 50; i++)
	{
		//auto x = xx { i };
		//v.push_back(x);
		v.push_back(xx { i });
	}
	#if 0
	for(int i = 0; i < 1024; i++)
	{
		v.pop_back();
		std::cout << "cap = " << v.capacity() << " size= " << v.size() << "\n";
		//v.push_back(xx { i });
	}
	#endif
}

void pushalot_lst()
{
	std::list<xx> l;
	for(int i = 0; i < 50; i++)
	{
		//auto x = xx { i };
		//l.push_back(x);
		l.push_back(xx { i });
	}
	#if 0
	for(int i = 0; i < 1024; i++)
	{
		l.pop_back();
		std::cout << " size= " << l.size() << "\n";
	}
	#endif
}

double average_dbl(const std::vector<double> & v)
{
	double res = 0.0;
	#if 0
	for(auto it = v.cbegin(); it != v.cend(); ++it)
	{
		res += *it;
	}
	#endif
	
	for(double e : v)
		res += e;
	
	return res / v.size();
}

template<typename X>
std::ostream& operator << (
	std::ostream& out,
	const std::vector<X> & vect)
{
	out << "{";
	for(auto it = vect.cbegin(); it != vect.cend(); ++it)
	{
		if(it != vect.cbegin())
			out << ", ";
		out << *it;
	}
	out << "}";
	return out;
}

template<typename X>
X average(const std::vector<X> & vect)
{
	X res { 0 };
	for(X e : vect)
		res = res + e;
	return res / vect.size();
}

std::vector<double> multiply_dbl(
	const std::vector<double> & p1,
	const std::vector<double> & p2)
{
	size_t n = p1.size();
	size_t m = p2.size();
	
	std::vector<double> mult(n + m - 1, 0);
	for(size_t i = 0; i < n + m - 1; ++i)
	{
		for(size_t j = 0; j <= i; ++j)
		{
			mult[i] += p1[j] * p2[i - j];
		}
	}
	return mult;
}

template<typename X>
std::vector<X> multiply(
	const std::vector<X> & p1,
	const std::vector<X> & p2)
{
	size_t n = p1.size();
	size_t m = p2.size();
	
	std::vector<X> mult(n + m - 1, 0);
	for(size_t i = 0; i < n + m - 1; ++i)
	{
		for(size_t j = 0; j <= i; ++j)
		{
			if(j >= n || i - j >= m)
				continue;
			mult[i] = mult[i] + p1[j] * p2[i - j];
		}
	}
	return mult;
}

int main( int argc, char* argv [] )
{
	//pushalot_vec();
	//pushalot_lst();
	
	std::vector<double> vd = { 2.0, 1, 4.5 };
	std::cout << average(vd) << "\n";
	
	std::vector<float> vf = { 2.0, 1, 4.5 };
	std::cout << average(vf) << "\n";
	
	std::vector<rational> vr = { 2, 1, rational(9, 2) };
	std::cout << average(vr) << "\n";
	
	std::cout << "\n\n";
	std::vector<double> m = { 0.1, 1 };
	for(int i = 2; i <= 9; ++i)
	{
		m = multiply(m, std::vector<double> { i / 10.0, 1 });
	}
	std::cout << m << "\n";
	
	#if 0
	std::vector<rational> mr = { rational(1, 10), 1 };
	for(int i = 2; i <= 9; ++i)
	{
		mr = multiply(mr, std::vector<rational> { rational(i, 10), 1 });
	}
	std::cout << mr << "\n";
	#endif
	
	std::cout << multiply(std::vector<rational> { rational(1, 2), 1 },
		multiply(std::vector<rational> { rational(1, 3), 1 },
			std::vector<rational> {rational(1, 4), 1 })) << "\n";
	
	std::vector<rational> mr = { rational(1, 2), 1 };
	std::vector<rational> res = mr;
	for(int i = 1; i <= 4; ++i)
	{
		res = multiply(res, mr);
	}
	std::cout << res << "\n";
	
	return 0;
}
