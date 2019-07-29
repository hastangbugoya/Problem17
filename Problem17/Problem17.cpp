// Problem17.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
void main()
{
	int ones[] = { 0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8 };
	int tens[] = { 0,0,6,6,5,5,5,7,6,6 };
	int total = 0;
	for (int i = 1; i <= 19; i++)
		total += ones[i];
	for (int i = 20; i <= 99; i++)
		total += tens[i / 10] + ones[i % 10];
	for (int i = 100; i <= 999; i++)
	{
		total += ones[i / 100] + 7; // hundred
		int j = i % 100;
		if (j > 0) total += 3; // and
		if (j < 20) total += ones[j];
		else {
			total += tens[j / 10]; // Xn
			total += ones[j % 10]; // nX
		}
	}
	total += 11; // onethousand
	printf("\n%d", total);
}

/*
	// The Mermaid Code
	#include <stdio.h>

	void main()
	{
			int ones[]={0,3,3,5,4,4,3,5,5,4};
			int teens[] = {3,6,6,8,8,7,7,9,8,8};
			int tens[]={0,0,6,6,5,5,5,7,6,6};
			int n = 1000;
			int total = 0;
			for (int i = 1; i <= n && i <= 9; i++)
					total += ones[i];
			for(int i = 10; i <= n && i <= 19; i++)
					total += teens[i -10];
			for(int i = 20; i <= n && i <= 99; i++)
					total += tens[i/10] + ones[i%10];       
			for(int i = 100; i <= n && i <= 999; i++)
			{
					total += ones[i / 100] + 7; // hundred
					int j = i % 100;
					if (j > 0) total+= 3; // and
					if (j < 10) total += ones[j];
					else if(j < 20) total += teens[j - 10];
					else {
									total += tens[j/10]; // Xn
									total += ones[j%10]; // nX
							}
					}
			total += 11; // onethousand
			printf("\n%d",total);
        
	}

*/