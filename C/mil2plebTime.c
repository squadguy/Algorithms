/*
 *
 * Converts time from military time to normal people time
 *
 */

#include<stdio.h>

int validHours(int *x); //Ensure time isn't greater than 23
int validMinutes(int *x); //Ensure minutes aren't greater than 59
void convertTime(int *x, int *hours, int *mins);

int main(){

	int time = 1562;
	int hoursValid, minsValid = 0;
	int *ptrTime = &time;
	int *ptrHoursValid = &hoursValid;
	int *ptrMinsValid = &minsValid;


	hoursValid = validHours(ptrTime);		
	minsValid = validMinutes(ptrTime);		

	convertTime(ptrTime, ptrHoursValid, ptrMinsValid);


	return 0;
}

int validHours(int *x)
{	
	int valid = 0;
	if(*x > 2359)
	       printf("not a valid time\n");	
	else
		valid = 1;

	return valid;
}

int validMinutes(int *x)
{
	int valid = 0;
	int minutes = *x % 100;
	
	if(minutes > 59)
		printf("Minutes Invalid\n");
	else
		valid = 1;

	return valid;

}

//need to set an AM and PM variable
void convertTime(int *x, int *hours, int *mins)
{
	if(*hours == 1 && *mins == 1 )
	{
		if(*x < 1300)
			printf("%d\n", *x);
		else
			printf("%d\n", *x-1200);
	}
	else
		printf("Incorrect format\n");
		
}
