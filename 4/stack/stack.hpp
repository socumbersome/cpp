
#ifndef STACK_INCLUDED
#define STACK_INCLUDED 1

#include <stdlib.h>
#include <initializer_list>

#define STACK_PLUS_AS_MEMBER 1

class stack
{
	private:
		size_t current_size;
		size_t current_capacity;
		
		// an invariant: tabk is always allocated with
		// a block of size current_capacity
		double *tab;
		
		void ensure_capacity(size_t c);
	
	public:
		stack();
		stack(const stack& s);
		stack(std::initializer_list<double> s);
		~stack();
		void operator = (const stack& s);
		void push (double d);
		void pop();
		void reset(size_t s);
		
		double& top();
		double top() const;
		
		size_t size() const { return current_size; }
		bool empty() const { return current_size == 0; }

		friend std::ostream& operator << (std::ostream& stream,
			const stack& s);

#if STACK_PLUS_AS_MEMBER == 1	
		stack operator + (const stack& s) const;
#endif
		double operator [] (unsigned int i) const;
		double& operator [] (unsigned int i);
		
		void operator += (double);
		void operator += (const stack& s);
};

std::ostream& operator << (std::ostream& stream, const stack& s);

#if STACK_PLUS_AS_MEMBER != 1
stack operator + (const stack& s1, const stack& s2);
#endif

#endif
