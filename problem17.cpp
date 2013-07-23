#include <iostream>
 
using namespace std;

/*
 * If the numbers 1 to 5 are written out in words:
 * one, two, three, four, five, then there are
 * 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand)
 * inclusive were written out in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example,
 * 342 (three hundred and forty-two) contains 23 letters
 * and 115 (one hundred and fifteen) contains 20 letters.
 * The use of "and" when writing out numbers is in compliance
 * with British usage.
 */

// Gets the name of a number under 1001 in words without spaces
string getName(int n)
{
  string units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

  if(n == 1000)
  {
    return "onethousand";
  }

  string name = "";

  // Get name of hundredths place
  if(n/100 != 0)
  {
    name += (units[n/100] + "hundred");
  }

  // Add an "and" if needed
  if((name.size() != 0) && (n%100 != 0))
  {
    name += "and";
  }

  // Remove hundredths place
  n = n%100;

  // If not teen or units place
  if(n/10 > 1)
  {
    name += (tens[n/10] + units[n%10]);
  }
  // If teen
  else if(n/10 == 1)
  {
    name += teens[n%10];
  }
  // If units place
  else
  {
    name += units[n%10];
  }

  return name;
}

int main()
{
  int numChars = 0;

  for(int i = 1; i <= 1000; i++)
  {
    numChars += getName(i).size();
  }

  cout << numChars;

  return 0;
}
