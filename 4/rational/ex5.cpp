
#include "rational.h"
#include "matrix.h"

int main( int argc, char* argv [ ] )
{
   rational r1( 1, 2 );
   rational r2( -2, 7 ); 
   rational r3( 1, 3 );
   rational r4( 2, 8 );
   matrix m1 = { { r1, r2 }, { r3, r4 } };
   std::cout << m1 << "\n";
   
   r1 = rational(1, -3);
   r2 = rational(2, 5);
   r3 = rational(2, 7);
   r4 = rational(-1, 7);
   matrix m2 = { { r1, r2 }, { r3, r4 } };
   std::cout << m2 << "\n";
   
   r1 = rational(4, 2);
   r2 = rational(7, -3);
   r3 = rational(1, 4);
   r4 = rational(-5, -2);
   matrix m3 = { { r1, r2 }, { r3, r4 } };
   std::cout << m3 << "\n";
   
   std::cout << (m1 * m2) * m3 << "\n";
   std::cout << m1 * (m2 * m3) << "\n\n";
   
   vector v = { rational(-3, 4), rational(2, 9) };
   std::cout << v << "\n";
   
   std::cout << m1(m2(v)) << " == " << (m1 * m2)(v) << "\n\n";
   
   std::cout << m1.determinant() * m2.determinant() << " == " \
		<< (m1 * m2).determinant() << "\n\n";	
   
   std::cout << m1 * m1.inverse() << "\n";
}

