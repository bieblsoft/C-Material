//.......1.........2.........3.........4.........5.........6.........7.........8.........
/*
	interface ISorter

	all Sorter classes have to be derived from this interface to
	make them implement the member functions

	Author: Gerhard Biebl
*/
//.......1.........2.........3.........4.........5.........6.........7.........8.........

#pragma once

template<typename Typ>
class ISorter
{
public:
	virtual void Sort(Typ* pTyp, int length)=0;
	virtual void Exchange(Typ* a, Typ* b)=0;
};