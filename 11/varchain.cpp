
#include "varchain.hpp"
#include <algorithm>


std::ostream& operator << ( std::ostream& out, const powvar & p )
{
   if( p.n == 0 )
   {
      out << "1"; // Should not happen, but we still have to print something.
      return out;
   }

   out << p.v;
   if( p.n == 1 )
      return out;

   if( p.n > 0 )
      out << "^" << p.n;
   else
      out << "^{" << p.n << "}";
   return out;
}


std::ostream& operator << ( std::ostream& out, const varchain& c )
{
   if( c. isunit( ))
   {
      out << "1";
      return out;
   }

   for( auto p = c. repr. begin( ); p != c. repr. end( ); ++ p )
   {
      if( p != c. repr. begin( ))
         out << ".";
      out << *p;
   }

   return out;
}


int varchain::power( ) const 
{
   int p = 0;
   for( auto pv : repr )
      p += pv. n;
   return p;
}

void varchain::normalize()
{
	std::sort(repr.begin(), repr.end(), [] (const powvar& p1,
		const powvar& p2) {
			return p1.v < p2.v;
		});
	
	std::vector< powvar > newrepr;
	for(size_t i = 0; i < repr.size(); ++i)
	{
		for(size_t j = i + 1; j < repr.size(); ++j)
		{
			if(repr[i].v == repr[j].v)
			{
				repr[i].n += repr[j].n;
				repr[j].n = 0;
			}
		}
		if(repr[i].n != 0)
			newrepr.push_back(repr[i]);
	}
	
	repr = newrepr;
}

varchain operator * ( varchain c1, const varchain& c2 )
{
	auto newrepr = c1.repr;
	newrepr.insert(newrepr.end(), c2.repr.begin(), c2.repr.end());
	return varchain(newrepr);
}

