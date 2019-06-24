// Project: chap 03 challenge 15

// > Write a program that receives from keyboard and outputs on screen
// > the primitives like char, short integer, long integer, float,
// > double, long double and string using scanf() / printf() as well as
// > cin / cout.

// To compile and launch, using the cygwin g++ compiler:
// g++ -std=c++14 challenge15.cpp && ./a.exe

// I did not write the C-style part. This exercise is not very interesting.

// Output:

// Key points to remember:

#include <iostream>

int main()
{
  std::cout << "101 C++ challenges - chapter 03, challenge 15" << std::endl;
  std::cout << "Write a char:" << std::endl;
  char c;
  std::cin >> c;
  std::cout << "You wrote the char: " << c << std::endl;

  std::cout << "Write a short integer: " << std::endl;
  short int i;
  std::cin >> i;
  std::cout << "You wrote the short int: " << i << std::endl;

  std::cout << "Write a long integer: " << std::endl;
  long int j;
  std::cin >> j;
  std::cout << "You wrote the long int: " << j << std::endl;

  std::cout << "Write a float: " << std::endl;
  float f0;
  std::cin >> f0;
  std::cout << "You wrote the float: " << f0 << std::endl;

  std::cout << "Write a double: " << std::endl;
  double f1;
  std::cin >> f1;
  std::cout << "You wrote the double: " << f1 << std::endl;

  std::cout << "Write a long double: " << std::endl;
  long double f2;
  std::cin >> f2;
  std::cout << "You wrote the long double: " << f2 << std::endl;

  std::cout << "Write a string: " << std::endl;
  std::string s;
  std::cin >> s;
  std::cout << "You wrote the string: " << s << std::endl;

  return 0;
}
