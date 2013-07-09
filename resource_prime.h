#ifndef RESOURCE_PRIME_H
#define RESOURCE_PRIME_H

#include <vector>
#include <memory>

using namespace std;

// Get prime numbers smaller than n using Sieve of Erathosthenes
shared_ptr<vector<long>> getPrimes(long n);

// Write first n prime numbers to file
void writeToFile(int n);

// Get nth prime number
long getNthPrime(int n);

// Get sum of prime numbers smaller than n
long long primeSum(long n);

// Get sum of first n prime numbers
long long primeNthSum(int n);

#endif
