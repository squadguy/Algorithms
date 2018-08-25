/*
 *
 * Converts time from military time to normal people time
 *
 */

#include<stdio.h>

int validHours(int *x); //Ensure time isn't greater than 23
int validMinutes(int *x); //Ensure minutes aren't greater than 59
void convertTime(int *x, int *hours, int *mins, char *);
char* aVp (int *x);

int main(){

	int time = 0;
	int hoursValid, minsValid = 0;
	char* aorp = "";
	int *ptrTime = &time;
	int *ptrHoursValid = &hoursValid;
	int *ptrMinsValid = &minsValid;

	hoursValid = validHours(ptrTime);		
	minsValid = validMinutes(ptrTime);		
	aorp = aVp(ptrTime);

	convertTime(ptrTime, ptrHoursValid, ptrMinsValid, aorp);


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

char* aVp (int *x)
{
	int hour = *x / 100;
	char * amVpm = "AM";

	if (hour > 11)
	{
		amVpm = "PM";
	}

	return amVpm;
}

//need to set an AM and PM variable
void convertTime(int *x, int *hours, int *mins, char *amORpm)
{
	if(*hours == 1 && *mins == 1 )
	{
		if(*x == 1200)
			printf("Noon");
		else if(*x == 0)
			printf("Midnight");
		else if(*x < 1300)
		{
			printf("%d", *x);
			printf(amORpm);
		}
		else
		{
			printf("%d", *x-1200);
			printf(amORpm);
		}
	}
	else
		printf("Incorrect format\n");
		
}
