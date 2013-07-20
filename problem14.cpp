#include <iostream>
#include <cstring>
 
using namespace std;

/*
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1)
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), it is
 * thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

// Calculates next number in the sequence
int next(int n)
{
  if(n%2 == 0)
  {
    return n/2;
  }

  return (3*n) + 1;
}

int main()
{
  const int SIZE = 1000000;
  int* steps = new int[SIZE];
  memset(steps, 0, SIZE);

  int max_index = 1;
  int max_count = 1;

  for(int i = 1; i < SIZE; i++)
  {
    int n = i;
    int count = 1;

    // Calculate the sequence until it deteriorates
    // into one of the previously calculated cases
    while(n != 1 && n >= i)
    {
      n = next(n);
      count++;
    }

    // If it did deteriorat into one of the previous cases,
    // add the number of steps from that case to the count
    if(n != 1)
    {
      count += (steps[n] - 1);
    }

    if(count > max_count)
    {
      max_count = count;
      max_index = i;
    }

    // Add count to list of numbers for which
    // total stopping time has been calculated
    steps[i] = count;
  }

  cout << max_index;

  delete[] steps;

  return 0;
}
