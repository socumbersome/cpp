
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
   
   matrix m12 = m1 * m2;
   std::cout << m12 << "\n";
   std::cout << m1.inverse() << "\n" << m1.determinant() << "\n";
}

