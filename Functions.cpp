#include "Functions.h"
using namespace std;

void tableSet()
{
	for (int i = 0; i <= MAX_INT_VALUE; i++)	//places integer values in corresponding
	{											//tables using first 3 values of taylor series
		sinTable[i] = i - (i*i*i / 6) + (i*i*i*i*i / 120);
		cosTable[i] = 1 - (i*i / 2)   + (i*i*i*i / 24);
	}
	for (int i = MAX_INT_VALUE + 1, double j = 0; j < 1; i++, j = j + 0.0001)
	{
		sinTable[i] = j - (j*j*j / 6) + (j*j*j*j*j / 120);	//0 will be stored twice in tables
		cosTable[i] = 1 - (j*j / 2)	  + (j*j*j*j / 24);
	}
	//note: to access a certain decimal value, multiply value by 1000, truncate to 4 digits, add MAX_INT_VALUE to it
}
double sin(double angle)	//assumes angle is in radians
{
	int integerPart = (int)angle;
	double fractionPart = ((double)(PRECISION))*(angle - integerPart);
	int fractionPartIndex = (int)fractionPart;
	double sinInt = sinTable[integerPart];
	double cosInt = sinTable[integerPart];
	double sinFrac = sinTable[MAX_INT_VALUE + fractionPartIndex];
	double cosFrac = cosTable[MAX_INT_VALUE + fractionPartIndex];
	return (sinInt*cosFrac) + (cosInt*sinFrac);
}

double cos(double angle)	//assumes angle is in radians
{
	int integerPart = (int)angle;
	double fractionPart = ((double)(PRECISION))*(angle - integerPart);
	int fractionPartIndex = (int)fractionPart;
	double sinInt = sinTable[integerPart];
	double cosInt = sinTable[integerPart];
	double sinFrac = sinTable[MAX_INT_VALUE + fractionPartIndex];
	double cosFrac = cosTable[MAX_INT_VALUE + fractionPartIndex];
	return (cosInt*cosFrac) - (sinInt*sinFrac);
}

double arctan(double angle)	//assumes angle is in radians
{
	int integerPart = (int)angle;
	double fractionPart = angle - integerPart;
}