#include <time.h>
#include <iostream>
using namespace std;

const int n = 750;

float TestData[n][n][n];

//helper function that will convert clock ticks to miliseconds
double diffClock(clock_t startClockTick, clock_t endClockTick)
{
	double diffClockTicks = endClockTick - startClockTick; //different clock ticks
	double diffMs = (diffClockTicks * 10) / CLOCKS_PER_SEC; //convert to miliseconds
	return diffMs;
}

//add values row by row
void rowOrder()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				TestData[i][j][k] = 1;
			}
		}
	}
}

//add values column by column
void columnOrder()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				TestData[k][j][i] = 1;
			}
		}
	}
}

/*
int main()
{
	clock_t begin1 = clock();
	rowOrder();
	clock_t end1 = clock();
	cout << "time for rows: " << diffClock(begin1, end1) << "ms" << endl;

	clock_t begin2 = clock();
	columnOrder();
	clock_t end2 = clock();
	cout << "time for cols: " << diffClock(begin2, end2) << "ms" << endl;

	return 0;
}
*/