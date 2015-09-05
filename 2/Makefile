
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11
CPP = g++

ex5 : Makefile   ex5.o rational.o matrix.o ex4 main
	$(CPP) $(Flags) -o ex5   ex5.o rational.o matrix.o 

ex5.o : Makefile   ex5.cpp   matrix.h rational.h vector.h 
	$(CPP) -c $(Flags) ex5.cpp -o  ex5.o

ex4 : Makefile   ex4.o rational.o matrix.o 
	$(CPP) $(Flags) -o ex4   ex4.o rational.o matrix.o 

ex4.o : Makefile   ex4.cpp   matrix.h rational.h vector.h 
	$(CPP) -c $(Flags) ex4.cpp -o  ex4.o

main : Makefile   main.o rational.o matrix.o 
	$(CPP) $(Flags) -o main   main.o rational.o matrix.o 

main.o : Makefile   main.cpp   matrix.h rational.h vector.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o


rational.o : Makefile   rational.cpp   rational.h 
	$(CPP) -c $(Flags) rational.cpp -o  rational.o


matrix.o : Makefile   matrix.cpp   matrix.h rational.h vector.h 
	$(CPP) -c $(Flags) matrix.cpp -o  matrix.o


