#ifndef RESOURCE_PRIME_H
#define RESOURCE_PRIME_H

#include <vector>
#include <memory>

using namespace std;

// Get prime numbers smaller than n using Sieve of Erathosthenes
shared_ptr<vector<long>> getPrimes(long n);

// Writes first n prime numbers to file
void writeToFile(long n);

// Get nth prime number
long getNthPrime(long n);

#endif
