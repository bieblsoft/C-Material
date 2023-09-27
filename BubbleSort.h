//.......1.........2.........3.........4.........5.........6.........7.........8.........
/*
	class BubbleSort

	template policy implementation of the classic BubbleSort Algorithm
	sorts arrays of any length and any type

	using a Comparer policy, we may change the direction of sorting without
	any code change in the Bubblesort algorithm at all.
	using differnt, interchangeable comparers, we might as well change
	the decision of sorting or not sorting.

	The classic Bubblesort compares each array member to it's neighbour,
	deciding wether to sort or not; sorting means the positions of the neighbours 
	are switched.

	This involves multiple iteration runs on the parts of the array that have 
	not already been sorted. Bubblesort typically starts slowly, increasing speed 
	with each iteration.
	Good for small to medium arrays, a sturdy and simple algorithm, easy to implement.
	Bad with large amounts of data.

	Author: Gerhard Biebl
*/
//.......1.........2.........3.........4.........5.........6.........7.........8.........

#pragma once
#include "ISorter.h"
#include "enumerations.h"
#include "Comparer.h"

template<typename Typ, typename Comparer >
class BubbleSort : public ISorter<Typ>
{
public:
	BubbleSort();
	~BubbleSort();
	void Sort(Typ* pArray, int Size);
	void Exchange( Typ* a, Typ* b );
private:
	Typ* pStart;
	Typ* pEnd;
	int Size;
	Comparer BSComparer;	// comparer instance
};

template<typename Typ, typename Comparer>
BubbleSort<Typ, Comparer>::BubbleSort() : pStart(0), pEnd(0)
{
}

template<typename Typ, typename Comparer>
BubbleSort<Typ, Comparer>::~BubbleSort(void)
{
}

template<typename Typ, typename Comparer>
void BubbleSort<Typ, Comparer>::Sort(Typ* pArray, int Size)
{
	pStart = pArray;	// this fools the const declaration !
	pEnd = pStart + Size;

	Typ* pFirst = pStart;
	bool changed = false;

	do
	{
		changed = false;
		Typ* pSecond = pFirst;
		for ( ; pSecond < pEnd; pSecond++ )
		{
			if ( BSComparer.compare( *pSecond, *(pSecond+1) ) )
			{
				Exchange( pSecond, pSecond+1 );
				changed = true;
			}
		}
	} while ( changed );
}

template<typename Typ, typename Comparer>
void BubbleSort<Typ, Comparer>::Exchange( Typ* a, Typ* b )
{
	Typ temp = *a;
	*a = *b;
	*b = temp;
}