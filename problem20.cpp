#include <iostream>
 
using namespace std;

/*
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 *
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!
 */
int main()
{
  const int n = 100;

  // Represent 200 digit integer as a reversed array
  const int NUM_DIGITS = 200;
  int factorial[NUM_DIGITS];

  // Initialize integer to 1
  factorial[0] = 1;

  for(int i = 1; i < NUM_DIGITS; i++)
  {
    factorial[i] = 0;
  }

  for(int i = 1; i <= n; i++)
  {
    // Multiply calculated factorial by i
    int carry = 0;

    for(int j = 0; j < NUM_DIGITS; j++)
    {
      // Multiply digit with i
      int product = factorial[j];
      product *= i;
      product += carry;
      factorial[j] = product%10;

      carry = product/10;
    }
  }

  int sum = 0;

  // Order of digits doesn't matter when finding sum of digits
  for(int i = 0; i < NUM_DIGITS; i++)
  {
    sum += factorial[i];
  }

  cout << sum;

  return 0;
}
