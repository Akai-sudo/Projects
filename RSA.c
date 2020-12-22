//generation of public and private keys
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

bool isPrime(int n)
{
    int dels = 0;
    for(int i = 1;  i <= n; i++) {
        if(n % i == 0) {
            dels++;
        }

        if(dels > 2) {
            //printf("NOT PRIME\n");
            return false;
        }
    }
    //printf("IS PRIME\n");
    return true;
}

long eulersTotient(long n, int p, int q)
{
    //return n * (1 - (1.0/p)) * (1 - (1.0/q));
    return ((p - 1) * (q - 1));
}

long randomNuMWithinRange(long topLimit)
{
    //srand(time(NULL));
    return (rand() % ((topLimit - 1 + 1) + 1));
}

int main()
{
   int keyCandidate1;
   int keyCandidate2;
   srand(time(NULL));

   printf("Generating 2 random primes, please wait..\n");

   do {
     keyCandidate1 = randomNuMWithinRange(INT_MAX - 1);
   } while(!isPrime(keyCandidate1));
   printf("Found one! (%d)\n", keyCandidate1);
   do {
     keyCandidate2 = randomNuMWithinRange(INT_MAX - 1);
   } while(!isPrime(keyCandidate2));
    printf("Found another! (%d)\n", keyCandidate2);
    //printf("Kandidata sta %d in %d\n", keyCandidate1, keyCandidate2);
    
    long n = keyCandidate1 * keyCandidate2;
    printf("Our prime base now is %ld.\n", n);        
    long fi = eulersTotient(n, keyCandidate1, keyCandidate2);

    if(fi > 0) {
        printf("We used Eulers function [ϕ] to acquire %ld from the prime base.\n", fi);
    }
    //int fi = 780;

    printf("\n");

    if(fi < 0 || n < 0) {
        printf("Oops! Something went wrong. Most likely overflow of long\n[%ld] / [%ld]\n", n, fi);
    } else {
        //generiramo e dokler ni tako praštevilo da ne deli našega fi
        printf("Generating random prime [e] to match 1 < e < %ld, \nplease wait...\n", fi);
        long i;
        do {
            i = randomNuMWithinRange(fi - 1);
            //printf("Evaluating if %ld is considered prime and nondivisible by %ld\n", i, fi);
        } while((!isPrime(i)) || (fi % i == 0));
        
        printf("\n");
        long e = i; 
        //printf("We generated [e]: %ld.\n", e);
        for(long d = 1; d <= fi; d++) {
            if(((e * d) % fi) == 1)
            {
                printf("[ Key generation complete! ]\n");
                printf("Your public encryption key is: %ld\n", e);
                printf("Your private encryption key is: %ld\n", d);
                break;
            }
        }
    }
    return 0;
}
