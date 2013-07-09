#include "resource_prime.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>

using namespace std;

/*
 * Generate a list of prime numbers till
 * a specified value and writes them to a text file.
 *
 * Note: Uses shared pointers. Must be compiled with C++11.
 */

const string primeFile = "prime_list.txt";

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

// Writes first n prime numbers to file
void writeToFile(long n)
{
  shared_ptr<vector<long>> primes = getPrimes(n);

  ofstream outstream;
  outstream.open(primeFile);

  typedef vector<long>::iterator Iterator;

  // Print to file
  for(Iterator i = primes->begin(); i != primes->end(); ++i)
  {
    outstream << *i << endl;
  }

  outstream.close();
}

// Get nth prime number
long getNthPrime(long n)
{
  ifstream instream;
  instream.open(primeFile);

  string line;
  // Set maximum string size to 12 characters
  // to prevent unnecessary resizing.
  line.reserve(12);

  // Skip to nth line
  for(int i = 1; i < n; i++)
  {
    getline(instream, line);
  }

  getline(instream, line);

  return atoi(line.c_str());
}
