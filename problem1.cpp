#include <iostream>
 
using namespace std;

/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5,
 * we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of
 * all the multiples of 3 or 5 below 1000.
 */
int main()
{
  int count_3 = 0;
  int count_5 = 0;
  int count_15 = 0;
  int sum = 0;

  while(count_3 < 1000 || count_5 < 1000)
  {

    // Add multiples of 3
    if(count_3 < 1000)
    {
      sum += count_3;
    }

    // Add multiples of 5
    if(count_5 < 1000)
    {
      sum += count_5;
    }

    // Subtract multiples of 15
    if(count_15 < 1000)
    {
      sum -= count_15;
    }

    count_3 += 3;
    count_5 += 5;
    count_15 += 15;
  }

  cout << sum;

  return 0;
}
