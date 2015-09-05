
#include "move.hpp"
#include "fifteen.hpp" 
#include <unordered_map>
#include <queue>


using leveltable = 
std::unordered_map< fifteen, size_t, 
                    size_t(*) ( const fifteen& ),
                    bool(*) ( const fifteen& , const fifteen& ) > ;


// True if f1 seems further from being solved than f2.

bool further( const fifteen& f1, const fifteen& f2 )
{
   return f1. distance( ) > f2. distance( );
}

size_t hash( const fifteen& f )
{
   return f. hashvalue( );
}

bool equals( const fifteen& f1, const fifteen& f2 )
{
   return f1. equals( f2 );
}


// state is the state that we are trying to solve.

// #if 0

leveltable 
solve( const fifteen& start )
{
   leveltable levels{ 0, hash, equals };

   std::priority_queue< fifteen, std::vector< fifteen >, 
                        bool(*) ( const fifteen& , const fifteen& ) > 
   unchecked{ further }; 

   unchecked. push( start );
   levels[ start ] = 0; 

   // We have start unexplored, at its level is zero.

   std::vector<move> moves = { move::up, move::down, move::left, move::right };
      // All possible moves in a vector.

   // As long as there is a state whose neighbours are unexplored,
   // we explore them:

   while( unchecked. size( ))
   {
	//   std::cout << "aa!\n";
      fifteen best = unchecked. top( );
      size_t level = levels [ best ]; 
         // The best state is the state that is closest to the
         // solution. level is the number of moves that was required
         // to reach it.
   
      std::cout << "best =\n" << best << "\n";
      std::cout << "distance = " << best. distance( ) << "\n";

      if( best. issolved( ))
         return levels;

      unchecked. pop( ); 
//std::cout << "bb!\n";
      for( auto m : moves )
      {
		  //std::cout << "cc!\n";
         fifteen next = best;
         try
         {
			// std::cout << "fg!\n";
            next. makemove( m );
          //  std::cout << "wer!\n";
            auto p = levels. find( next );
          //  std::cout << "gf!\n";
            if( p == levels. end( ) || level + 1 < p -> second ) 
            {
               // We did not reach next before, or we reached it
               // in more steps. 
			//	std::cout << "dd!\n";
               levels[ next ] = level + 1; 
            //   std::cout << "ee!\n";
               unchecked. push( next );
            }
         }
         catch( illegalmove& m ) { /* catch and do nothing */ } 
      }
   }

   return levels;  // In move we trust.  
}

// #endif

std::list< move > findpath( const leveltable& levels,
                            fifteen f, size_t level )
{

	std::vector<move> moves = { move::up, move::down, move::left, move::right };
		// All possible moves in a vector.
	
	std::list< move > path;
	fifteen prev;
	bool found = false;
	move thism;
	if(level > 0)
	{
		for(auto p : levels)
		{
			if(p.second == level - 1)
			{
				for(auto m : moves)
				{
					try{
						prev = p.first;
						prev.makemove(m);
						if(prev.equals(f))
						{
							path = findpath(levels, p.first, level - 1);
							found = true;
							thism = m;
							break;
						}
					}
					catch( illegalmove& m ) { /* catch and do nothing */ }
				}
			}
			if(found)
			{
				path.push_front(thism);
				break;
			}
		}
	}
	
	return path;
}
 




int main( int argc, char* argv [] )
{
   fifteen f{ { 1, 3, 4, 12 }, { 5, 2, 7, 11 }, { 9, 6, 14, 10 }, { 13, 15, 0, 8 } } ;
  

   auto dist = solve(f);
#if 1
   for( const auto& p : dist )
   {
      std::cout << "---------------------------\n";
      std::cout << p.first << " " << p. second << "\n";
   }
#endif
   auto path = findpath( dist, fifteen( ), dist[ fifteen( ) ] );
   for( move m : path )
      std::cout << m << ", ";//"\n";

   return 0;
}


