#include <iostream>
 
using namespace std;

/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */
int main()
{
  const long long n = 600851475143;
  long long num = n;
  int i = 2;

  // Prime factorize number
  while(i*i < num)
  {
    // If prime factor found, divide num
    if(num%i == 0)
    {
      num /= i;
    }
    // If all occurences of prime factor are
    // used, got to the next prime num
    else
    {
      i++;
    }
  }

  if(num > 0)
  {
    cout << num;
  }

  return 0;
}
