//.......1.........2.........3.........4.........5.........6.........7.........8.........
/*
	class SortingMachine

	used to instantiate a configurable sorter object

	Author: Gerhard Biebl
*/
//.......1.........2.........3.........4.........5.........6.........7.........8.........

#include "BubbleSort.h"
#include "QuickSort.h"
#include "ISorter.h"

template<typename Typ, typename ISorter >
class SortingMachine
{
public:
	ISorter Sorter;
};