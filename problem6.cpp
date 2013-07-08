#include <iostream>
 
using namespace std;

/*
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 * Hence the difference between the sum of the squares of the
 * first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the
 * first one hundred natural numbers and the square of the sum.
 */
int main()
{
  long n = 100;

  // Sum of first n natural numbers squared
  long sum = (n*(n+1))/2;
  long sumSquared = sum*sum;

  //Sum of square of first n natural numbers
  long sumOfSquares = (n*(n+1)*(2*n + 1))/6;

  long diff = sumSquared - sumOfSquares;

  cout << diff;

  return 0;
}
