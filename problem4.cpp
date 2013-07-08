#include <iostream>
 
using namespace std;

/*
 * A palindromic number reads the same both ways. The
 * largest palindrome made from the product of two
 * 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the
 * product of two 3-digit numbers.
 */

/*
 * The palindrome must be of the form
 * xyzzyx. This integer can be expressed as
 * 100000x + 10000y + 1000z + 100z + 10y + x
 * = 100001x + 10010y + 1100z
 * = 11(9091x + 910y + 100z).
 * So one of the two 3 digit numbers must
 * be divisible by 11, which reduces the numbers
 * we have to check.
 */
int main()
{
  // x cannot be 0 since it's the leading digit
  // and even the smallest combination of 100*100 =10000
  // which is larger than 4 digits.
  for(int x = 9; x > 0; x--)
  {
    for(int y = 9; y >= 0; y--)
    {
      for(int z = 9; z >= 0; z--)
      {
        int palindrome = 11*(9091*x + 910*y + 100*z);

        // Checking for the two 3 digit numbers.
        // One of them must be a multiple of 11.
        for(int factor = 990; factor >= 110; factor-=11)
        {
          if(palindrome%factor == 0)
          {
            int otherFactor = palindrome/factor;

            // If other factor is also 3 digits
            if(99 < otherFactor && otherFactor < 1000)
            {
              cout << palindrome;
              return 0;
            }
          }
        }
      }
    }
  }

  return 0;
}
