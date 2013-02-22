#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  //Creates an input file stream named 'reader':
  ifstream reader(“test.txt”);
  while(reader.good())
  {
    string temp;
    getline(reader, temp);
    cout << temp << endl;
  }
  reader.close();
  return 0;
}
