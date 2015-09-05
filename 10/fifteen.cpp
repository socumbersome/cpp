
#include "fifteen.hpp"

fifteen::fifteen()
{
   size_t p = 1;
   for(size_t i = 0; i < dimension; ++i)
	for(size_t j = 0; j < dimension; ++j)
	{
		table[i][j] = p;
		++p;
	}
   table[dimension-1][dimension-1] = 0;
   open_i = dimension - 1;
   open_j = dimension - 1;
}

fifteen::fifteen( 
	std::initializer_list< std::initializer_list< size_t >> init )
{
	size_t ii = 0, jj = 0;
	for(auto row : init)
	{
		for(auto e : row)
		{
			table[ii][jj] = e;
			if(e == 0)
			{
				open_i = ii;
				open_j = jj;
			}
			++jj;
		}
		++ii;
		jj = 0;
	}
}

std::ostream& operator << ( std::ostream& stream,
	const fifteen& f )
{
   //stream << std::setw(/*2**/f.dimension);
   for(size_t i = 0; i < f.dimension; ++i)
   {
	for(size_t j = 0; j < f.dimension; ++j)
	{
		if(j != 0)
			stream << "|";
		stream << f.table[i][j];
	}
	if(i != f.dimension - 1)
		stream << "\n";
   }
   return stream;
}

size_t fifteen::hashvalue( ) const
{
	size_t res = 1;
	for(size_t i = 0; i < dimension; ++i)
		for(size_t j = 0; j < dimension; ++j)
		{
			if(table[i][j] != 0)
			{
				res += 3 * table[i][j] - i - j;
			}
		}
	return res;
}

bool fifteen::equals( const fifteen& other ) const
{
	if(dimension != other.dimension)
		return false;
	for(size_t i = 0; i < dimension; ++i)
		for(size_t j = 0; j < dimension; ++j)
			if(table[i][j] != other.table[i][j])
				return false;
	return true;
}

bool fifteen::issolved( ) const
{
	return equals(fifteen());
}

void fifteen::makemove( move m )
{
	switch(m)
	{
		case move::up :
		if(open_i > 0)
		{
			//std::cout << "1" << open_i << ", " << open_j <<  "\n";
			std::swap(table[open_i][open_j], table[open_i - 1][open_j]);
			//std::cout << "lend\n";
			open_i--;
		}
		else
			throw illegalmove(m);
		break;
		case move::down :
		if(open_i < dimension - 1)
		{
			//std::cout << "2\n";
			std::swap(table[open_i][open_j], table[open_i + 1][open_j]);
			open_i++;
		}
		else
			throw illegalmove(m);
		break;
		case move::left :
		if(open_j > 0)
		{
			//std::cout << "3\n";
			std::swap(table[open_i][open_j], table[open_i][open_j - 1]);
			open_j--;
		}
		else
			throw illegalmove(m);
		break;
		case move::right :
		if(open_j < dimension - 1)
		{
			//std::cout << "4\n";
			std::swap(table[open_i][open_j], table[open_i][open_j + 1]);
			open_j++;
		}
		else
			throw illegalmove(m);
		break;
	}
}

size_t fifteen::distance( ) const
{	
	size_t res = 0;
	for(size_t i = 0; i < dimension; ++i)
		for(size_t j = 0; j < dimension; ++j)
			res += distance(std::make_pair(i, j),
				solvedposition(table[i][j]));
	return res;
}

