#include<stdio.h>
#include<stdbool.h> //need for bool values :: C99 compliant
#include<string.h> //need for memset

//C program to print all prime numbers smaller than or equal to n using Sieve of Eratosthenes.
//Useful while n <= 10 million
//O=(log n(log n))


void SieveOfEratosthenes(int n)
{
	// Create boolean array "prime[0..n]" and init
	// all entries as true.  A value in prime[i] will
	// finally be false if it is not a prime.
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	
	//Check all indexes between 2 and sqrt(n)

	for (int p=2; p*p<=n; p++)
	{
		//If prime[p] is unchanged, then it's prime
		if (prime[p] == true)
		{
			// Update all multiple of P as not prime
			for (int i = p*2; i<=n; i +=p)
				prime[i] = false;
		}
	}

	// Print all primes
	for (int p=2; p<=n; p++)
		if (prime[p])
			printf("%d\n", p);
}

int main()
{
	SieveOfEratosthenes(1200);


	return 0;
}
