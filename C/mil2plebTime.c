/*
 *
 * Converts time from military time to normal people time
 *
 */

#include<stdio.h>

void validHours(int *x);
void validMinutes(int *x);

int main(){

	int time = 2350;
	int *ptrTime = &time;

	validHours(ptrTime);		
	validMinutes(ptrTime);		

	return 0;
}

void validHours(int *x)
{	
	if(*x > 2359)
	       printf("not a valid time --- exiting\n");	
	else
		printf("%d\n", *x);
}

void validMinutes(int *x)
{
	int minutes = *x % 100;
	
	if(minutes > 59)
		printf("%d\n", "Minutes Invalid --- exiting\n");

}
