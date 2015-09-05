
#include "varchain.hpp"
#include "polynomial.hpp"	
#include "bigint.hpp"
#include "rational.hpp"


template< typename N >
polynomial< N > exptaylor( unsigned int n )
{
   varchain v;

   N fact = 1;

   polynomial< N > result;
   for( unsigned int i = 0; i < n; ++ i )
   {
      result[v] += fact;
      v = v * powvar( "x" );
      fact = fact / (i+1);
   }

   return result;
}

int main( int argc, char* argv [] )
{
   std::cout << "hello\n";
#if 0
   polynomial< rational > pol;

   int N = 50;

   pol[ { } ] = 1;
   pol[ { "x" } ] = rational( 1, N ); 

   
   polynomial< rational > res = 1;
 
   for( int i = 0; i < N; ++ i )
      res = res * pol;

   std::cout << "rsult = " << res << "\n";

   std::cout << " taylor expansion = " << exptaylor<rational>(20) << "\n";

   std::cout << "difference = " ;  
   std::cout << res - exptaylor<rational> ( 40 ) << "\n";
#endif
#if 1
	polynomial<double> smp;
	smp[ { } ] = 1;
	smp[ { "x" } ] = 1;
	auto pol = smp;
	for(int i = 0; i < 4; ++i)
		pol = pol * smp;
	std::cout << pol << "\n";
	
	polynomial<rational> smp2;
	smp2[ { } ] = 1;
	smp2[ { {"x", 2}, {"y", 1}, {"z", 3} } ] = 1;
	auto pol2 = smp2;
	for(int i = 0; i < 3; ++i)
		pol2 = pol2 * smp2;
	std::cout << pol2 << "\n";
	
	polynomial<rational> smp3;
	smp3[ { } ] = 3;
	smp3[ { {"x", 1}, {"y", 1} } ] = 1;
	auto pol3 = smp3;
	for(int i = 0; i < 5; ++i)
		pol3 = pol3 * smp3;
	std::cout << pol3 << "\n";
#endif
   return 0;
}


