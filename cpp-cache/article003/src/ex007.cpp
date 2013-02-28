#include <cstdio>
#include <iostream>

int main() {
  int fc,fcpp;
  std::cout << "Type a number: ";
  scanf("%d",&fc);
  std::cout << "Type the same number: ";
  std::cin >> fcpp;
  std::cout << "fc = " << fc << ", fcpp = " << fcpp << std::endl;
  return 0;
}
