
#include <iostream>
#include "stack.hpp"
#include <stdexcept>
#include <sstream>

stack::stack() :
	current_size {0},
	current_capacity {1},
	tab {new double[current_capacity]}
{ /*std::cout << "constructor\n";*/ }

stack::stack(const stack& s) :
	current_size {s.current_size},
	current_capacity {s.current_capacity},
	tab {new double[s.current_capacity]}
{
	//std::cout << "copy constructor\n";
	for(size_t i = 0; i < current_size; ++i)
		tab[i] = s.tab[i];
}

stack::~stack()
{
	//std::cout << "destructor\n";
	delete [] tab;
}

void stack::operator = (const stack& s)
{
	if(tab != s.tab)
	{
		//std::cout << "assignment\n";
		delete [] tab;
		current_size = s.current_size;
		current_capacity = s.current_capacity;
		tab = new double[s.current_capacity];
		for(size_t i = 0; i < current_size; ++i)
			tab[i] = s.tab[i];
	}
	//else
	//	std::cout << "self assignment\n";
}

void stack::push(double d)
{
	if(current_size >= current_capacity)
		ensure_capacity(current_capacity + 1);
	
	tab[current_size] = d;
	current_size++;
}

void stack::pop()
{
	if(current_size == 0)
		throw std::runtime_error("Invoked `pop` on empty stack");
	current_size--;
}

void stack::reset(size_t s)
{
	if(current_size < s)
	{
		std::ostringstream ss;
		ss << "Invoked `reset(" << s << ")` but stack had "
			<< current_size << " elements";
		throw std::runtime_error(ss.str());
	}
	current_size = s;
}

double& stack::top()
{
	if(current_size == 0)
		throw std::runtime_error("Invoked `pop` on empty stack");
	return tab[current_size - 1];
}

double stack::top() const
{
	if(current_size == 0)
		throw std::runtime_error("Invoked `pop` on empty stack");
	return tab[current_size - 1];
}

void stack::ensure_capacity(size_t c)
{
	if(current_capacity < c)
	{
		// we set new capacity to max(c, 2*current_capacity)
		if(c < 2 * current_capacity)
			c = 2 * current_capacity;
		
		double* newtab = new double[c];
		for(size_t i = 0; i < current_size; ++i)
			newtab[i] = tab[i];
		
		current_capacity = c;
		delete [] tab;
		tab = newtab;
	}
}

std::ostream& operator << (std::ostream& stream, const stack& s)
{
	stream << "Stack{";
	if (s.empty())
		stream << "}";
	else
		stream << s.top() << " ...}";
	return stream;
}
