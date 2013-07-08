#include <iostream>
 
using namespace std;

/*
 * 2520 is the smallest number that can be divided by each
 * of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly
 * divisible by all of the numbers from 1 to 20?
 */

// Finds GCD of two numbers
// See https://en.wikipedia.org/wiki/Euclidean_algorithm#Implementations
long long gcd(long long a, long long b)
{
  if(b == 0)
  {
    return a;
  }
  else
  {
    return gcd(b, a%b);
  }
}

// Finds LCM of two numbers using GCD
long long lcm(long long a, long long b)
{
  return (a*b)/gcd(a, b);
}

// Finds LCM of all integers from 1 to n
long long lcmn(int n)
{
  if(n == 1)
  {
    return 1;
  }
  
  return lcm(n, lcmn(n-1));
}

int main()
{
  cout << lcmn(20);

  return 0;
}
