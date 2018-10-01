/* CHALLENGE */
/* Given a lower bound and upper bound of a whole number set, return the sum of each value within the set */

/* Three functions to return the sum of a whole number set, given a lower and upper bound; in increasing efficiency */

#include <stdio.h>

int slow(int*, int*);
int faster(int, int);
int fastest(int*, int*);

int main()
{
	int low = 1;
	int high = 101;
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

	int sum = ((*high + *low) * length/2);

/*	int sum = (int)(((double)(*high + *low) / 2) * length); */

	return sum;
}
