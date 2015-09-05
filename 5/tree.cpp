
#include "tree.hpp"
#include <stdexcept>
//#define DEBUG

tree::tree(const tree& t) :
	pntr { t.pntr }
{
	#ifdef DEBUG
	std::cout << "Copy constructor\n";
	#endif
	pntr->refcnt++;
}

tree::~tree()
{
	pntr->refcnt--;
	
	if(pntr->refcnt == 0)
		delete pntr;
}

void tree::operator = (tree&& t)
{
	#ifdef DEBUG
	std::cout << "Rvalue assignment\n";
	#endif
	std::swap(pntr, t.pntr);
}

void tree::operator = (const tree& t)
{
	#ifdef DEBUG
	std::cout << "Copying assignment\n";
	#endif
	//std::cout << "ca\n";
	// we want to reuse rvalue assignment, so...
	*this = /*std::move(*/tree(t)/*)*/; // ?
	//*this = std::move(t); // core dumped! 
}

const std::string& tree::functor() const
{
	return pntr->f;
}

const tree& tree::operator[] (size_t i) const
{
	if(i > nrsubtrees())
		throw std::runtime_error("Tree index out of bounds");
	return pntr->subtrees[i];
}

size_t tree::nrsubtrees() const
{
	return pntr->subtrees.size();
}

std::ostream& operator << (std::ostream& stream, const tree& t)
{
	stream << t.functor() << "(";
	for(size_t i = 0; i < t.nrsubtrees(); ++i)
	{
		if(i != 0)
			stream << ", ";
		stream << t[i];
	}
	stream << ")";
	return stream;
}

std::string& tree::functor()
{
	ensure_not_shared();
	return pntr->f;
}

tree& tree::operator[] (size_t i)
{
	ensure_not_shared();
	if(i > nrsubtrees())
		throw std::runtime_error("Tree index out of bounds");
	return pntr->subtrees[i];
}

void tree::ensure_not_shared()
{
	if(pntr->refcnt >= 2)
	{
		trnode* brand_new = new trnode {pntr->f, pntr->subtrees, 1};
		pntr->refcnt--;
		pntr = brand_new;
	}
}

tree subst(const tree& t, const std::string& var, const tree& val)
{	
	if(t.functor() == var && t.nrsubtrees() == 0)
	{
		return val;
	}
	else
	{
		std::vector< tree > sbtrees;
		for(size_t i = 0; i < t.nrsubtrees(); ++i)
			sbtrees.push_back(subst(t[i], var, val));
		
		return tree {t.functor(), std::move(sbtrees)};
	}
}
