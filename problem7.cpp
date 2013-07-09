#include "resource_prime.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
 * By listing the first six prime numbers:
 * 2, 3, 5, 7, 11, and 13,
 * we can see that the 6th prime is 13.
 *
 * What is the 10001st prime number?
 */
int main()
{
  const int n = 10001;

  // Created a list of primes
  // using the Sieve of Erathostenes
  // for 10 million.
  // n*log(n) is approximately
  // the nth prime number.
  // 10 million > n*(log(n))
  // writeToFile(9999999);

  cout << getNthPrime(n);

  return 0;
}
