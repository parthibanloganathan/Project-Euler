#include <iostream>
 
using namespace std;

/*
 * A Pythagorean triplet is a set of three natural numbers,
 * a < b < c, for which, a^2 + b^2 = c^2
 *
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */
int main()
{
  // Generating Pythagorean triplet using Euclid's formula
  // See http://en.wikipedia.org/wiki/Pythagorean_triple#Generating_a_triple
  
  // By definition, m > n > 0
  int m = 2;
  int n = 1;

  // a, b and c form a Pythagoren triplet
  int a = m*m - n*n;
  int b = 2*m*n;
  int c = m*m + n*n;

  while(a+b+c < 1000)
  {
    // Find abc when a+b+c = 1000
    // for all values of m and n such that a+b+c <= 1000
    for(n = 1; (n < m) && (a+b+c <= 1000); n++)
    {
      a = m*m - n*n;
      b = 2*m*n;
      c = m*m + n*n;

      if(a+b+c == 1000)
      {
        cout << a*b*c;

        return 0;
      }
    }

    // Increment m and reset n
    m++;
    n = 1;

    a = m*m - n*n;
    b = 2*m*n;
    c = m*m + n*n;
  }

  return 0;
}
