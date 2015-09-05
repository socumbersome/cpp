
#include "tree.hpp"


int main( int argc, char* argv [ ] )
{
   tree t1( std::string( "a" ));
   tree t2( std::string( "b" )); 
   tree t3 = tree( std::string( "f" ), { t1, t2 } ); 

   std::vector< tree > arguments = { t1, t2, t3 };
   std::cout << tree( "F", std::move( arguments )) << "\n";

   t2 = t3;
   t2 = std::move(t3);
   
	while(true)
	{
		tree t4(std::string("c"));
		tree t5(std::string("g"), { t2, t4, t1 } );
		
		t5 = t3;
	}
   
}



