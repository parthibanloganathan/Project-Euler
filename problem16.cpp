#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;

/*
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 2^1000?
 */

// Doubles the integer represented by a string
string doubleNum(string n)
{
  int carry = 0;
  stringstream intString;
  string result;

  for(int i = n.size() - 1; i >= 0; i--)
  {
    // Get digit, double it and add the carry
    int digit = n[i] - '0';
    digit *= 2;
    digit += carry;

    // If last iteration, append all of digit to intString
    // because there is no carry
    if(i == 0)
    {
      intString << digit;
    }
    // If not last iteration, append last digit of digit
    // and set the rest to carry
    else
    {
      intString << digit%10;
      carry = digit/10;
    }

    result = intString.str() + result;

    // Clear stringstream
    intString.str(string());
  }

  return result;
}

int main()
{
  int sum = 0;

  // 2^0 = 1
  string result = "1";

  for(int i = 1; i <= 1000; i++)
  {
    result = doubleNum(result);
  }

  for(int i = 0; i < result.size(); i++)
  {
    sum += (result[i] - '0');
  }

  cout << sum;

  return 0;
}
