
#include "rational.h"
#include <cassert>

// Complete these methods:

// gives gcd(abs(n1), abs(n2)) !
int rational::gcd( int n1, int n2 )
{
	if(n1 < 0)
		n1 = -n1;
	if(n2 < 0)
		n2 = -n2;
	if(n1 == 0)
		return n2;
	return rational::gcd(n2 % n1, n1);
}

void rational::normalize( )
{
	if(num == 0)
	{
		denum = 1;
	}
	else
	{
		int d = gcd(num, denum);
		num /= d; denum /= d;
		if(num < 0 && denum < 0 || num >= 0 && denum < 0)
		{
			num = -num;
			denum = -denum;
		}
	} 
}

rational operator - ( rational r )
{
	return rational(-r.num, r.denum);
}

rational operator + ( const rational& r1, const rational& r2 )
{
	int nnum = r1.num * r2.denum + r1.denum * r2.num;
	int ndenum = r1.denum * r2.denum;
	return rational(nnum, ndenum);
}

rational operator - ( const rational& r1, const rational& r2 )
{
	int nnum = r1.num * r2.denum - r1.denum * r2.num;
	int ndenum = r1.denum * r2.denum;
	return rational(nnum, ndenum);
}	

rational operator * ( const rational& r1, const rational& r2 )
{
	int nnum = r1.num * r2.num;
	int ndenum = r1.denum * r2.denum;
	return { nnum, ndenum };
}		

rational operator / ( const rational& r1, const rational& r2 )
{
	//assert(r2.num != 0);
       // 	If you want to check, use throw.

	int nnum = r1.num * r2.denum;
	int ndenum = r1.denum * r2.num;
	return rational(nnum, ndenum);
}

bool operator == ( const rational&r1, const rational& r2 )
{
	return r1.num == r2.num && r1.denum == r2.denum;;
}
bool operator != ( const rational& r1, const rational& r2 )
{
	return !(r1 == r2);
}

std::ostream& operator << ( std::ostream& stream, const rational& r )
{
	stream << "Rat{" << r.num << "/" << r.denum << "}";
	return stream;
}

