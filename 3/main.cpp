
#include <iostream>
#include "stack.hpp"

int main( int argc, char* argv [ ] )
{
	//while(true)
	for(unsigned int i = 0; i < 1/*10000*1000*/; ++i)
	{
		stack s1;
		s1.push(45); s1.push(45); s1.push(46);
		std::cout << "checkpoint1\n";
		stack s2 = s1;
		
		for(unsigned int j = 0; j < 20; ++j)
			s2.push(j * j);
		
		s1 = s2;
		std::cout << "checkpoint2\n";
		s1 = s1;
		
		/*const*/ stack& sconst = s1;
		sconst.top() = 20;
		sconst.push(15);
		std::cout << sconst;
	}
}

