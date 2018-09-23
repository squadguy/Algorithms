#include<stdio.h>
#include<math.h>

int* makeMagicSquare(int);
int getMidIndex(int);
int getMinIndex(int, int);

int main()
{

	int sideLength = 5;

	makeMagicSquare(sideLength);

	return 0;
}

int* makeMagicSquare(int sideLength) 
{
	int magicSquare [sideLength * sideLength];
	int midIndex = getMidIndex(sideLength);
	int minIndex = getMinIndex(midIndex, sideLength);

	printf("%d\n", minIndex);

	return magicSquare;
}

int getMidIndex(int sideLength)
{
	int midIndex = ((sideLength * sideLength)/2);

	return midIndex;
}

int getMinIndex(int midIndex, int sideLength)
{
	int minIndex = midIndex + sideLength;
	
	return minIndex;
}
