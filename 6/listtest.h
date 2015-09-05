
#ifndef LISTTEST_INCLUDED
#define LISTTEST_INCLUDED   1

#include <list> 
#include <vector> 
#include <string> 
#include <fstream>
#include <iostream>

// I agree that the use of namespace in this little exercise
// is a bit exagerate, but one has to learn this technique.

namespace listtest 
{
   void sort( std::list< std::string > & l );
}

std::ostream&
operator << ( std::ostream& , const std::list< std::string > & ); 


#endif 

