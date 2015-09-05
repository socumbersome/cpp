
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11
CPP = g++


main : Makefile   main.o varchain.o bigint.o rational.o 
	$(CPP) $(Flags) -o main   main.o varchain.o bigint.o rational.o 

main.o : Makefile   main.cpp   rational.hpp bigint.hpp polynomial.hpp varchain.hpp 
	$(CPP) -c $(Flags) main.cpp -o  main.o


varchain.o : Makefile   varchain.cpp   varchain.hpp 
	$(CPP) -c $(Flags) varchain.cpp -o  varchain.o


bigint.o : Makefile   bigint.cpp   bigint.hpp 
	$(CPP) -c $(Flags) bigint.cpp -o  bigint.o


rational.o : Makefile   rational.cpp   rational.hpp bigint.hpp 
	$(CPP) -c $(Flags) rational.cpp -o  rational.o


