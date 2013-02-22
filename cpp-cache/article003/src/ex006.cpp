#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  // Creates an output file stream named 'writer':
  ofstream writer(“test.txt”);

  // Write some text to the file:
  writer << “Hello” << endl;
  writer << “This is a test file” << endl;
  writer.close();
  return 0;
}
