#include "resource_prime.h"
#include <iostream>
 
using namespace std;

/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */
int main()
{
  const int n = 2000000;

  // Created a list of primes
  // using the Sieve of Erathostenes
  // for 10 million.
  // writeToFile(9999999);

  long long sum = primeSum(n);

  cout << sum;

  return 0;
}
