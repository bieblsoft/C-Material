//.......1.........2.........3.........4.........5.........6.........7.........8.........
/*
	class Comparer

	template policy to use with the example's sorting algorithms.

	It decides wether to sort or not by comparing two neighbour array members.
	This can be influenced by the Directions enumeration.

	Author: Gerhard Biebl
*/
//.......1.........2.........3.........4.........5.........6.........7.........8.........

#pragma once
#include "enumerations.h"

template<typename Typ, Directions dir> 
class Comparer
{
public:
	Comparer(void) { dirs = dir; };
	~Comparer(void) {};
	bool compare( Typ a, Typ b )
	{
		if ( dir == Directions::ascending )
		{
			if ( a > b ) 
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if ( a < b ) 
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	Directions dirs;
private:

};