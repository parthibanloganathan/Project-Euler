#include <iostream>
#include <algorithm>
 
using namespace std;

/*
 * Starting in the top left corner of a 2×2 grid, and only
 * being able to move to the right and down, there are exactly
 * 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
 */

/* Calculates the combination nCk
 * using a dynamic programming approach.
 * The combinations of all subsets are calculated
 * first in order to prevent redundant computation
 * of recurring combinations which would arise in
 * a recursive algorithm.
 */
long long combination(int n, int k)
{
  // C[i][j] represents iCj
  // n+1 and k+1 account for 0
  long long C[n+1][k+1];
  
  for(int i = 0; i <= n; i++)
  {
    // Limit j to min(i, k) to avoid calculating unnecessary
    // values of iCj where j > k
    for(int j = 0; j <= min(i, k); j++)
    {
      // nC0 = nCn = 1
      if(j == 0 || j == i)
      {
        C[i][j] = 1;
      }
      // By recursive definition of nCk,
      // nCk = (n-1)C(k-1) + (n-1)Ck
      // See en.wikipedia.org/wiki/Binomial_coefficient#Recursive_formula
      else
      {
        C[i][j] = C[i-1][j-1] + C[i-1][j];
      }
    }
  }

  return C[n][k];
}

int main()
{
  const int SIZE = 20;

  /* We have to move 20 steps left and 20 steps down.
   * So a total of 40 steps must be made. We need
   * to permute these steps to find the total number
   * of paths.
   *
   * Permuting (m+n) objects where m are of one type
   * and n are of another type, we get
   * P(m+n) = (m+n)!/m!n! = (m+n)Cm = (m+n)Cn
   */

  long long result = combination(SIZE + SIZE, SIZE);

  cout << result;

  return 0;
}
