#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
 
using namespace std;

/*
 * Generate a list of prime numbers till
 * a specified value and writes them to a text file.
 *
 * Note: Uses shared pointers. Must be compiled with C++11.
 */

// Get prime numbers smaller than n using Sieve of Erathosthenes
shared_ptr<vector<long>> getPrimes(long n)
{
  vector<bool> isPrime(n, true);
  long i = 2;
  long p;

  // 0 and 1 are not prime
  isPrime[0] = isPrime[1] = false;

  while(i < n)
  {
    p = 2*i;

    // Mark all multiples of p as composite
    while(p < n)
    {
      isPrime[p] = false;
      p += i;
    }

    // Search for next prime number to start from
    i++;
    while(!isPrime[i])
    {
      i++;
    }
  }

  // Pick all primes from the sieve
  // and copy them to a separate vector
  shared_ptr<vector<long>> primes = shared_ptr<vector<long>>(new vector<long>());

  for(long i = 0; i < n; i++)
  {
    if(isPrime[i] == true)
    {
      primes->push_back(i);
    }
  }

  return primes;
}

int main()
{
  const long n = 10000000;
  shared_ptr<vector<long>> primes = getPrimes(n);

  ofstream primeFile;
  primeFile.open("list_of_primes.txt");

  typedef vector<long>::iterator Iterator;

  // Print to file
  for(Iterator i = primes->end() - 1; i != primes->begin() - 1; i--)
  {
    primeFile << *i << endl;
  }

  primeFile.close();

  return 0;
}
