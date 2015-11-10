#include <bits/stdc++.h>        // include library
using namespace std;            // calling functions from the library normally needs to have a prefix "std::"
                                // however this statement means we don't need that ("cout" instead  of "std::cout")
int main() {
  freopen("input.txt", "r", stdin);       // open input file, make it the standard input
  freopen("output.txt", "w", stdout);     // open output file, make it the standard output
  
  int x, y, answer;   // declare variables
  
  cin >> x >> y;      // read two numbers from input
  answer = x + y;     // compute the sum of the two numbers
  cout << answer;     // print the answer to the output file
  
  return 0;           // signal that the program has ended successfully
}                     // if a program returns something other than 0, it will be interpreted that an error has occured
