#include<stdio.h>
#include<math.h>

//int* makeMagicSquare(int);
void buildMagicSquare(int);
int getMidIndex(int);
int getMinIndex(int, int);
int getNextIndex(int, int, int);

int main()
{

	int sideLength = 5;

	buildMagicSquare(sideLength);

	return 0;
}

/*
int* makeMagicSquare(int sideLength) 
{
//	int magicSquare [sideLength * sideLength];
	int * magicSquare = NULL;
	int midIndex = getMidIndex(sideLength);
	int minIndex = getMinIndex(midIndex, sideLength);

	printf("%d\n", minIndex);

	magicSquare = buildMagicSquare(sideLength, minIndex);

	return magicSquare;
}
*/

int getMidIndex(int sideLength)
{
	int midIndex = ((sideLength * sideLength)/2);

	return midIndex;
}

int getMinIndex(int sideLength, int midIndex)
{
	int minIndex = midIndex + sideLength;
	
	return minIndex;
}

void buildMagicSquare(int sideLength)
{
	int midIndex = getMidIndex(sideLength);
	int curIndex = getMinIndex(sideLength, midIndex);
	int iterator = 1;
	int magicSquare[sideLength * sideLength];


	for (int i = 1; i < ((sideLength * sideLength + 1)); ++i )
	{
		magicSquare[curIndex] = i;

		printf("%d:", magicSquare[curIndex]);
		printf("%d\n", curIndex);

		curIndex = getNextIndex(sideLength, curIndex, iterator);

		if( iterator != sideLength)
		{
			iterator++;
		}
		else
		{
			iterator = 1;
		}
		

	}

}


int getNextIndex(int sideLength, int curIndex, int iterator)
{
	/*             3                  SIDE LEGNTH
	 *             *
	 *      --------------- 
	 *      |      |      |
	 *      0      1      2             BLOCK
	 *      +      +      +
	 *     /|\    /|\    /|\
	 *    0 1 2  1 2 3  0 1 2          SUBINDEX
	 *    = = =  = = =  = = =
	 *    0 1 2  3 4 5  6 7 8           INDEX
	 *  |[a,b,c,|d,e,f,|g,h,i]|         ARRAY
	 * 
	 */

	int nextIndex; // We're returing this val
	int block;
	int subIndex;
	int nextBlock;
	int nextSubIndex;

	block = (curIndex / sideLength);
	subIndex = (curIndex % sideLength);


	nextSubIndex = subIndex;              // Init this val equal to curSubIndex

	//Get Next Block
	if (iterator != sideLength)
	{
		nextBlock = block + 1;
		
		if (nextBlock >= sideLength)
		{
			nextBlock = nextBlock - sideLength;
		}
	}
	else
	{
		nextBlock = block + 2;
		if (nextBlock >= sideLength)
		{
			nextBlock = nextBlock - sideLength;
		}
	}

	printf("%d\n", nextBlock);	

	// Get Next SubIndex	
	if (iterator != sideLength)
	{
		if (subIndex == sideLength - 1)
		{
			nextSubIndex = 0;
		}
		else
		{
			++nextSubIndex;
		}
	}

	nextIndex = (nextBlock * sideLength) + nextSubIndex;
//	printf("%d\n", nextIndex);

	return nextIndex;
	
}
