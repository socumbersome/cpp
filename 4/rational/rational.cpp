
#include "rational.h"
#include <cassert>
#include <stdexcept>

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
	return rational(-r.getnum(), r.getdenum());
}

rational operator + ( const rational& r1, const rational& r2 )
{
	int nnum = r1.getnum() * r2.getdenum() + r1.getdenum() * r2.getnum();
	int ndenum = r1.getdenum() * r2.getdenum();
	return rational(nnum, ndenum);
}

rational operator - ( const rational& r1, const rational& r2 )
{
	int nnum = r1.getnum() * r2.getdenum() - r1.getdenum() * r2.getnum();
	int ndenum = r1.getdenum() * r2.getdenum();
	return rational(nnum, ndenum);
}	

rational operator * ( const rational& r1, const rational& r2 )
{
	int nnum = r1.getnum() * r2.getnum();
	int ndenum = r1.getdenum() * r2.getdenum();
	return { nnum, ndenum };
}		

rational operator / ( const rational& r1, const rational& r2 )
{
	if(r2.getnum() == 0)
		throw std::invalid_argument( "dividing by zero" );
	//assert(r2.num != 0);
       // 	If you want to check, use throw.

	int nnum = r1.getnum() * r2.getdenum();
	int ndenum = r1.getdenum() * r2.getnum();
	return rational(nnum, ndenum);
}

bool operator == ( const rational&r1, const rational& r2 )
{
	return r1.getnum() == r2.getnum() && r1.getdenum() == r2.getdenum();;
}
bool operator != ( const rational& r1, const rational& r2 )
{
	return !(r1 == r2);
}

std::ostream& operator << ( std::ostream& stream, const rational& r )
{
	stream << "Rat{" << r.getnum() << "/" << r.getdenum() << "}";
	return stream;
}

