#include <string>
#include <iostream>
using namespace std; 

int main() 
{ 
  // Make some number variables: 
  int wholeNumber = 5;
  float decimalNumber = 5.5; 
  
  /* Make some letter variables: 
  ** Notice how we use single quotes 
  ** for characters, and double quotes 
  ** for strings. */ 
  string greeting = "Hello there"; 
  char punctuation = '!'; 
  // Make a boolean variable: 
  bool isTrue = false; 
  
  // Print our variables added together:
  cout << wholeNumber + decimalNumber << endl; 
  cout << greeting + punctuation << endl; 
  cout << isTrue << endl; 
  
  return 0; 
}
