#include <iostream>
 
using namespace std;

/*
 * You are given the following information, but you may prefer
 * to do some research for yourself.
 *
 *  1 Jan 1900 was a Monday.
 *  Thirty days has September,
 *  April, June and November.
 *  All the rest have thirty-one,
 *  Saving February alone,
 *  Which has twenty-eight, rain or shine.
 *  And on leap years, twenty-nine.
 *  A leap year occurs on any year evenly divisible by 4, but
 *  not on a century unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the
 * twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */
int main()
{
  // Number of Sundays on 1st of the month
  int count = 0;

  // Number of days per month in a non-leap year
  int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // 1st January 1900 is a Monday
  // where {Sun: 0, Mon: 1, Tue: 2, ... Sat: 6}
  int first = 1;

  // Find day of 1st January 1901
  first = (first + 365)%7;

  // Years from 1901 to 2000
  for(int y = 1901; y <= 2000; y++)
  {
    // Months of the year
    for(int m = 0; m < 12; m++) 
    {
      // If the 1st of the month is a Sunday
      if(first == 0)
      {
        count++;
      }

      // Find the day of the 1st of the following month
      int nextMonth = (m+1)%12;
      first += daysPerMonth[nextMonth];

      // If next month is February
      if(nextMonth == 1)
      {
        // If leap year (ie. the year is divisible by 4 unless it's a
        // century which is not divisible by 400)
        if((y%4 == 0) && ((y%100 != 0) || (y%400 == 0)))
        {
          first--;
        }
      }

      first %= 7;
    }
  }

  cout << count;

  return 0;
}
