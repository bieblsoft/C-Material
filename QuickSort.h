//.......1.........2.........3.........4.........5.........6.........7.........8.........
/*
	class QuickSort

	QuickSort is the fastest known sorting algorithm (at least the fastest i know)

	Like the BubbleSort class, it has a configurable Comparer for the sort decision,
	so we may sort ascending or descending without changing a line of code in the 
	Algorithm itself.

	QuickSort uses recursion, which makes it memory-consuming but unequaled fast.
	Recursion takes some profit of multi-core or Hyperthreading CPU's.
	QuickSorts tactical advantage is to split the sorting task into smaller parts
	which are called "Partitions". Small partitions sort quickly, but have to be 
	combined until the whole array is sorted. This makes QuickSort a
	somehow more complicated, not easily implementable Algorithm.


	Author: Gerhard Biebl
*/
//.......1.........2.........3.........4.........5.........6.........7.........8.........

#pragma once
#include "Partitioner.h"
#include "enumerations.h"

template<typename Typ, typename Comparer>
class QuickSort : public ISorter<Typ>
{
public:
	QuickSort();
	~QuickSort(void);
	void Sort( Typ* pArray, int Size );
	void Exchange( Typ* a, Typ* b );
	void QSort( Typ* pArray, Typ* pSart, Typ* pEnd );

private:
	Comparer QSComparer;
	Partitioner<Typ, Comparer> QSPartitioner;
};

template<typename Typ, typename Comparer>
QuickSort<Typ, Comparer>::QuickSort()
{
}

template<typename Typ, typename Comparer>
QuickSort<Typ, Comparer>::~QuickSort()
{
}

template<typename Typ, typename Comparer>
void QuickSort<Typ, Comparer>::Sort(Typ* pArray, int Size)
{
	Typ* pStart = (Typ*) pArray;
	Typ* pEnd = pStart + Size;

	QSort( pArray, pStart, pEnd );
}

template<typename Typ, typename Comparer>
void QuickSort<Typ, Comparer>::QSort( Typ* pArray, Typ* pStart, Typ* pEnd )
{
	Typ* pLeft = pStart;
	Typ* pRight = pEnd;
	Typ* pivot = pEnd;

	if ( pStart < pEnd )
	{
		pivot = QSPartitioner.CreatePartition( pArray, pLeft, pRight );
		QSort( pArray, pLeft, pivot - 1 );
		QSort( pArray, pivot + 1, pRight );
	}
}

template<typename Typ, typename Comparer>
void QuickSort<Typ, Comparer>::Exchange( Typ* a, Typ* b )
{
	Typ temp = *a;
	*a = *b;
	*b = temp;
}