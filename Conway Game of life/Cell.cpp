#include "Cell.h"

Cell::Cell() { /* ... */ }

bool Cell::GetIsAlive() const
{
	return mIsAlive;
}

Cell& Cell::SetIsAlive(const bool& isAlive)
{
	mIsAlive = isAlive;
	return *this;
}