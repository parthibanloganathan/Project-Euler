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
 * Find the maximum total from top to bottom in triangle.txt (problem67.txt), a 15K text
 * file containing a triangle with one-hundred rows.
 */
int main()
{
  vector< vector<int> > pyramid;

  ifstream numstream("problem67.txt");

  string line;
  // Set maximum string size to 15 characters
  // to prevent unnecessary resizing.
  line.reserve(100);

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
