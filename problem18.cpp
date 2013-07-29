#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

/*
 * By starting at the top of the triangle below and moving
 * to adjacent numbers on the row below, the maximum total
 * from top to bottom is 23.
 *
 *    3
 *   7 4
 *  2 4 6
 * 8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below:
 *
 *               75
 *              95 64
 *             17 47 82
 *            18 35 87 10
 *           20 04 82 47 65
 *          19 01 23 75 03 34
 *         88 02 77 73 07 63 67
 *        99 65 04 28 06 16 70 92
 *       41 41 26 56 83 40 80 70 33
 *      41 48 72 33 47 32 37 16 94 29
 *     53 71 44 65 25 43 91 52 97 51 14
 *    70 11 33 28 77 73 17 78 39 68 17 57
 *   91 71 52 38 17 14 91 43 58 50 27 29 48
 *  63 66 04 68 89 53 67 30 73 16 69 87 40 31
 * 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 */
int main()
{
  vector< vector<int> > pyramid;

  ifstream numstream("problem18.txt");

  string line;
  // Set maximum string size to 15 characters
  // to prevent unnecessary resizing.
  line.reserve(15);

  // Load pyramid into vector
  while(!numstream.eof())
  {
    getline(numstream, line);

    // Don't attempt to copy blank line
    if(line.size() == 0)
    {
      break;
    }

    vector<int> row;
    int num;

    // Copy integers in line into row
    stringstream linestream(line);

    while(linestream >> num)
    {
      row.push_back(num);
    }

    pyramid.push_back(row);
  }  

  numstream.close();

  // Calculate longest path
  int height = pyramid.size();

  // Combine layers together from the bottom, ensuring
  // that the maximum path is selected for each element
  for(int i = height-2; i >= 0; i--)
  { 
    int size = pyramid[i].size();

    // Merge the row with the row below it by adding the
    // largest neighbor to each element in the row
    for(int j = 0; j < size; j++)
    {
      // For each element in the row, add the largest element
      // it can reach in the next row
      pyramid[i][j] += max(pyramid[i+1][j], pyramid[i+1][j+1]);
    }
  }

  cout << pyramid[0][0];

  return 0;
}
