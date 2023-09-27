//.......1.........2.........3.........4.........5.........6.........7.........8.........
/*
	class Partitioner

	used in the QuickSort algorithm to set up small parts of an array which may be 
	sorted independantly.
	uses the Comparer class to adapt to configurable sorting directions.

	Author: Gerhard Biebl
*/
//.......1.........2.........3.........4.........5.........6.........7.........8.........

#pragma once

template<typename Typ, typename Comparer>
class Partitioner
{
public:
	Typ* CreatePartition(	Typ const * pData, 
									Typ* leftMargin, 
									Typ* rightMargin );
	void Exchange ( Typ* a, Typ* b );
private:
	Comparer QSComparer;
};

template<typename Typ, typename Comparer>
Typ* Partitioner<Typ, Comparer>::CreatePartition(	Typ const * pData, 
											Typ* leftMargin, 
											Typ* rightMargin )
{
	Typ* pStart = leftMargin;
	Typ* pEnd = rightMargin;
	Typ pivot = *rightMargin;

	while ( pStart < pEnd )
	{
		if ( QSComparer.dirs == Directions::ascending )
		{
			// if you omit the Comparer function call,
			// Quicksort gets even faster !

			//while ( ( *pStart <= pivot ) && ( pStart < rightMargin ) )
			while ( ( ! QSComparer.compare( *pStart, pivot ) ) && ( pStart < rightMargin ) )
			{
				++pStart;
			}
			//while ( ( *pEnd >= pivot ) && ( pEnd > leftMargin ) )
			while ( ( ! QSComparer.compare( pivot, *pEnd ) ) && ( pEnd > leftMargin ) )
			{
				--pEnd;
			}

			if ( pStart < pEnd )
			{
				Exchange ( pStart, pEnd );
			}

			if ( *pStart > pivot )
			{
				Exchange ( pStart, rightMargin );
			}
		}
		else
		{
			//while ( ( *pStart >= pivot ) && ( pStart < rightMargin ) )
			while ( ( ! QSComparer.compare( *pStart, pivot ) ) && ( pStart < rightMargin ) )
			{
				++pStart;
			}
			//while ( ( *pEnd <= pivot ) && ( pEnd > leftMargin ) )
			while ( ( ! QSComparer.compare( pivot, *pEnd ) ) && ( pEnd > leftMargin ) )
			{
				--pEnd;
			}

			if ( pStart < pEnd )
			{
				Exchange ( pStart, pEnd );
			}

			if ( *pStart < pivot )
			{
				Exchange ( pStart, rightMargin );
			}
		}
	}
	
	return pStart;
}

template<typename Typ, typename Comparer>
void Partitioner<Typ, Comparer>::Exchange( Typ* a, Typ* b )
{
	Typ temp = *a;
	*a = *b;
	*b = temp;
}