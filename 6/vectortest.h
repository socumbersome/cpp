
#ifndef VECTORTEST_INCLUDED
#define VECTORTEST_INCLUDED  1

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

namespace vectortest
{
   void sort( std::vector< std::string > & v );
}

std::ostream& 
operator << ( std::ostream& , const std::vector< std::string > & );


#endif 

