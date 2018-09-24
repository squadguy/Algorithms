/*********************************************************************
 *                                                                   *
 *                                                                   *
 *                       MAGIC SQUARE SOLVER                         *
 *                                                                   * 
 *                   Solves for any odd sized side                   * 
 *                                                                   *
 *                          Chris Wampnar                            *
 *                                                                   * 
 *                                                                   *
 *********************************************************************/

/*
 * This program uses an array to represent a square.
 *
 * Algorithm:
 * # Logically divide array into "blocks" which represent square's rows, eqaul to side length
 * # Find middle index of array (and hence, the "Square").
 * # Move to the middle of the next "block" (sidelength distance away)
 * # This index is the minimum number, or 1, always.
 * # Now, we go from populate the array from number 2 to the Max number (sidelength * sidelength)
 * # Initalize an interator to 1.
 * # If interator isn't equal to sidelength - the next index is over one block and increase subindex by 1 ("wrap both block and index if you're all the way to the right")
 * # If iterator is equal to side length - move over two blocks (wrap when needed) do not increase subindex
 * # Continue to do this until all array values are full
 * 
 * This algorithm multiplies the next logical block value by the side length and then adds the current subindex +1 to determine the next value's index in the array.  See diagram in function "getNextIndex"
 *
 */

#include<stdio.h>

void buildMagicSquare(int);
int getMidIndex(int);
int getMinIndex(int, int);
int getNextIndex(int, int, int);

int main()
{

	int sideLength = 21;

	buildMagicSquare(sideLength);

	return 0;
}

//Finds Middle Index of Array
int getMidIndex(int sideLength)
{
	int midIndex = ((sideLength * sideLength)/2);

	return midIndex;
}

//Determines where the Minimum Value (1) Goes
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

	//Applies the values to the square
	for (int i = 1; i < ((sideLength * sideLength + 1)); ++i )
	{
		//Set the value to the current index
		magicSquare[curIndex] = i;

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

//Print square
	int total = 0;
	for (int i = 0; i < (sideLength * sideLength); ++i)
	{
		if(i == 0)
		{
			printf("%d:", magicSquare[i]);
			total = total + magicSquare[i];
		}
		else 
			if(i % sideLength != 0 )
			{
				printf("%d:", magicSquare[i]);
				total = total + magicSquare[i];
			}
			else
			{
				printf("   =%d", total);
				total = 0;
				printf("\n%d:", magicSquare[i]);

				total = total + magicSquare[i];
			}
	}

	printf("   =%d", total);
	
	printf("\n");

}


int getNextIndex(int sideLength, int curIndex, int iterator)
{
	/*    Example Side Length = 3
	 *
	 *             3                  SIDE LEGNTH
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

	int nextIndex;              // We're returing this val
	int block;                  // This is a logical partition to represent a subArray 
	int subIndex;               // The subindex in the logical subArray
	int nextBlock;
	int nextSubIndex;

	block = (curIndex / sideLength);       //Determine which logical block (subarray) we're in
	subIndex = (curIndex % sideLength);    // Determine the subindex were at within the logical block


	nextSubIndex = subIndex;               // Init this val equal to curSubIndex

	//Get Next Block
	if (iterator != sideLength)
	{
		nextBlock = block + 1;
	        // Account and handle "wrap around" for blocks (last block "loops back" to first block)	
		if (nextBlock >= sideLength)
		{
			nextBlock = nextBlock - sideLength;
		}
	}
	else   //Jump right two blocks - do not increase subindex 
	{
		nextBlock = block + 2;
	        // Account and handle "wrap around" for blocks (last block "loops back" to first block)	
		if (nextBlock >= sideLength)
		{
			nextBlock = nextBlock - sideLength;
		}
	}


	// Get Next SubIndex	
	if (iterator != sideLength) // Needed for when iterator equals side length: if they are equal don't increase sub index
	{
		if (subIndex == sideLength - 1) //Subindex "wrap around" last subindex points to back to first
		{
			nextSubIndex = 0;
		}
		else
		{
			++nextSubIndex;
		}
	}

	nextIndex = (nextBlock * sideLength) + nextSubIndex;

	return nextIndex;
	
}
