/* Finds the sum of a set */

#include <stdio.h>

int slow(int*, int*);
int faster(int, int);
int fastest(int*, int*);

int main()
{
	int low = 6;
	int high = 11;
	int total;

	total = slow(&low, &high);
	printf("%d\n", total);
	total = faster(low, high);
	printf("%d\n", total);
	total = fastest(&low, &high);
	printf("%d\n", total);




	return 0;
}

/* Takes n iterations */
int slow(int* low, int* high)
{
	int sum = 0;
	int i;

	for( i = *low; i < (*high+1); i++)
	{
		sum = sum + i; 
	}


	return sum;
}

/* Takes n/2 iterations */
int faster(int low, int high)
{
	int sum = 0;

	/* Handles sets with odd number of values */
	if ((high - low)%2 != 0)
	{
		sum = high;
		--high;
	}

	while(low != high)
	{
		sum += (low + high);
		
		++low;
		--high;

	}

	sum = sum + low;

	return sum;
}

/* Constant Time */
int fastest(int* low, int* high)
{
	int length = (*high - *low)+1;

	int sum = (int)(((double)(*high + *low) / 2) * length);

	return sum;
}
