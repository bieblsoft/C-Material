//.......1.........2.........3.........4.........5.........6.........7.........8.........
/*

	Sort tester

	test program for the provided sorting algorithms.
	featuring high speed time measurement using MS Windows performance counters.

	Author: Gerhard Biebl
*/
//.......1.........2.........3.........4.........5.........6.........7.........8.........

#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

#include "enumerations.h"
#include "Comparer.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "SortingMachine.h"

void main()
{
	// small character array. Will be sorted very quickly with whatever 
	// algorithm you will use. 10 characters long
	// consumes 3.2 µs on my computer with BubbleSort
	// consumes 3.2 µs on my computer with QuickSort - equally fast
	//string Text = "Hello World";

	// large character array. Shows the differences of the sorting algorithms
	// when it comes to hard work. 66 characters long
	// consumes 122.5 µs on my computer with BubbleSort
	// consumes  35.7 µs on my computer with QuickSort - 4 times faster
	//string Text = "now is the time for all good men to come to the aid of their party";

	// gigantic array - preamble of the declaration of Independancy of the US
	// 1227 characters long
	// consumes 43,924.1 µs on my computer with BubbleSort
	// consumes  1,354.5 µs on my computer with QuickSort - 40 times faster
	string Text = "We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness. — That to secure these rights, Governments are instituted among Men, deriving their just powers from the consent of the governed, — That whenever any Form of Government becomes destructive of these ends, it is the Right of the People to alter or to abolish it, and to institute new Government, laying its foundation on such principles and organizing its powers in such form, as to them shall seem most likely to effect their Safety and Happiness. Prudence, indeed, will dictate that Governments long established should not be changed for light and transient causes; and accordingly all experience hath shewn that mankind are more disposed to suffer, while evils are sufferable than to right themselves by abolishing the forms to which they are accustomed. But when a long train of abuses and usurpations, pursuing invariably the same Object evinces a design to reduce them under absolute Despotism, it is their right, it is their duty, to throw off such Government, and to provide new Guards for their future security.";
	char* TextChars = (char*) Text.c_str();

	LARGE_INTEGER Frequency;
	LARGE_INTEGER StartTimeHF;
	LARGE_INTEGER EndTimeHF;

	long elapsed = 0;
	double RunTime = 0.0;

	// Bubblesort testing
	cout << endl << "Bubblesort test" << endl << endl;

	cout << "Unsorted: >" << TextChars << "<" << endl;

	SortingMachine<char, 
		BubbleSort<char, 
			Comparer<char, 
				Directions::ascending> > > BubbleSorter;

	SortingMachine<char, 
		QuickSort<char, 
			Comparer<char, 
				Directions::ascending> > > QuickSorter;

	QueryPerformanceFrequency ( &Frequency );
	QueryPerformanceCounter ( &StartTimeHF );

	BubbleSorter.Sorter.Sort( &TextChars[0], strlen(TextChars) - 1 );

	QueryPerformanceCounter ( &EndTimeHF );
	elapsed = (long) ( EndTimeHF.QuadPart - StartTimeHF.QuadPart );
	RunTime =  ( (double) ( elapsed ) / Frequency.QuadPart );

	cout << "Sorted:   " << ">" <<
		TextChars << "<;" << endl << 
		"Bubblesort needed " << 
		setiosflags( ios::fixed ) << 
		setprecision( 10 ) <<
		RunTime << 
		" sec." << 
		endl;

	// Quicksort testing
	cout << endl << "Quicksort test" << endl << endl;

	Text = "We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness. — That to secure these rights, Governments are instituted among Men, deriving their just powers from the consent of the governed, — That whenever any Form of Government becomes destructive of these ends, it is the Right of the People to alter or to abolish it, and to institute new Government, laying its foundation on such principles and organizing its powers in such form, as to them shall seem most likely to effect their Safety and Happiness. Prudence, indeed, will dictate that Governments long established should not be changed for light and transient causes; and accordingly all experience hath shewn that mankind are more disposed to suffer, while evils are sufferable than to right themselves by abolishing the forms to which they are accustomed. But when a long train of abuses and usurpations, pursuing invariably the same Object evinces a design to reduce them under absolute Despotism, it is their right, it is their duty, to throw off such Government, and to provide new Guards for their future security.";
	//Text = "now is the time for all good men to come to the aid of their party";
	//Text = "Hello World";
	TextChars = (char*) Text.c_str();

	cout << "Unsorted: >" << TextChars << "<" << endl;

	QueryPerformanceCounter ( &StartTimeHF );

	QuickSorter.Sorter.Sort( TextChars, strlen(TextChars) - 1 );

	QueryPerformanceCounter ( &EndTimeHF );
	elapsed = (long) ( EndTimeHF.QuadPart - StartTimeHF.QuadPart );
	RunTime =  ( (double) ( elapsed ) / Frequency.QuadPart );

	cout << "Sorted:   " << ">" <<
		TextChars << "<;" << endl << 
		"Quicksort needed  " << 
		setiosflags( ios::fixed ) << 
		setprecision( 10 ) <<
		RunTime << 
		" sec." << 
		endl;
}