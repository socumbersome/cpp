
#include <iostream>
#include "stack.hpp"

int main( int argc, char* argv [ ] )
{
	#if 0
	//while(true)
	for(unsigned int i = 0; i < 1/*10000*1000*/; ++i)
	{
		stack s1 {45, 42, 46 }
		std::cout << "checkpoint1\n";
		stack s2 = s1;
		
		for(unsigned int j = 0; j < 20; ++j)
			s2.push(j * j);
		
		s2 += s2;
		std::cout << "checkpoint2\n";
		s1 = s1;
		
		/*const*/ stack& sconst = s1;
		sconst.top() = 20;
		sconst.push(15);
		std::cout << (sconst + s1)[2];
	}
	#endif
	stack s1 = { 4, 5, 67 };
	//s1.push(2);
	std::cout << s1 << " , " << s1[1] << "\n\n";
	stack s2 = {1, 2};
	s2 += s1;
	std::cout << s1 << s2[3] << s2.size() << "\n";
}

