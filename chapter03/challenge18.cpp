// Project: chap 03 challenge 18

// > Write a program that receives two numbers from keyboard and then
// > swaps them using a call by address and a call by reference.


// To compile and launch, using the cygwin g++ compiler:
// g++ -std=c++14 challenge18.cpp && ./a.exe


// Output:
// $ g++ -std=c++14 challenge18.cpp && ./a.exe
// 101 C++ challenges - chapter 03, challenge 18
// Before swapping:
// a=3, b=7, c=9, d=13
// a and b will be switched by adress, c and will be switched by reference
// After swapping:
// a=7, b=3, c=13, d=9
  
// Key points to remember:
// Nothing special, the author wants us to manipulate pointers and references

#include <iostream>
void switchByAddress(int* first, int* second)
{
  int temp = *first;
  *first = *second;
  *second = temp;
}

void switchByReference(int& first, int& second)
{
  int temp=first;
  first = second;
  second = temp;
}


int main()
{
  std::cout << "101 C++ challenges - chapter 03, challenge 18" << std::endl;
  int a{3};
  int b{7};
  int c{9};
  int d{13};
  std::cout << "Before swapping:" << std::endl;
  std::cout << "a=" << a << ", b=" << b <<", c=" << c <<", d=" << d << std::endl;
  std::cout << "a and b will be switched by adress, c and will be switched by reference" << std::endl;
  switchByAddress(&a, &b);
  switchByReference(c, d);
  std::cout << "After swapping:" << std::endl;
  std::cout << "a=" << a << ", b=" << b <<", c=" << c <<", d=" << d << std::endl;
  return 0;
}

