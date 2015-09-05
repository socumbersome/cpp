
#include <fstream>
#include <iostream>
#include <chrono> 

#include "listtest.h"
#include "vectortest.h"

void readfile( std::istream& input, std::vector< std::string > & vect ) 
{
   if( !input. good( ))
      return;  // It was a short pleasure. 
   
   std::string lastword; 
   int c = input. get( ); 
   while( input. good( ))
   {
	  lastword.clear();
      while(input.good() && !isspace(c) && !ispunct(c))
      {
		  lastword.push_back(c);
		  c = input.get();
	  }
	  
	  if(!lastword.empty())
	  {
		  vect.push_back(lastword);
	  }
	  
      c = input. get( ); 
   }

   // A file should not end without a newline, but we need
   // to do something when it happens.

   if( lastword. size( ))
   {
     vect.push_back(lastword);
   }

}

// Anonymous namespace. This means that this function
// is guaranteed to be unique in the program, so that
// we don't have to worry about makelowercase functions defined
// in other files.

namespace
{
   // 'inline' is ignored by the compiler, but it makes me feel better.

   inline void makelowercase( std::string& s )
   {
      for( char& c : s )
         c = tolower(c);
   }
}

void makelowercase( std::vector< std::string > & vect )
{
   for( auto& s : vect )
      makelowercase(s);
}


std::list< std::string > 
makelist( const std::vector< std::string > & vect )
{
   std::list< std::string> result;

   for( const auto& s : vect )
      result. push_back(s);
   return result;

}

int main( int argc, char* argv [] )
{

   std::vector< std::string > vect;

   // This use of int is one of those ugly remainders of C--.

   for( int i = 1; i != argc; ++ i )
   {
      std::ifstream input{ argv[i] }; 
      if( !input )
      {
         std::cerr << "could not open input file " << argv[i] << "\n";
      }
      else
      {
         readfile( input, vect ); 
      }
   }

   makelowercase( vect );

   std::cout << vect << "\n";

   std::list< std::string > lst = makelist( vect ); 

   auto t1 = std::chrono::high_resolution_clock::now( ); 
   vectortest::sort( vect );
   //listtest::sort(lst);
   auto t2 = std::chrono::high_resolution_clock::now( );

   std::chrono::duration< double > d = ( t2 - t1 );
   std::cout << vect << "\n";

   std::cout << "sorting took " << d. count( ) << " seconds\n";
   return 0;
}


