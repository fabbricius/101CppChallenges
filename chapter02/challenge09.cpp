// Project: chap 02 challenge 09
// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
// Write a program to find all such numbers up to 10000 which are equal to the sum of the factorial of their digits.

// To compile using the cygwin g++ compiler:
// g++ -std=c++14 challenge09.cpp && ./a.exe

// Output:
// 101 C++ challenges - chapter 02, challenge 09
// 1 is curious.
// 2 is curious.
// 145 is curious.
// 40585 is curious.


#include <iostream>
#include <string>

// This factorial function works for a number between 0 and 9.
int factorial(const int& n)
{
  // I could have used this function recursively, as the author did in the book.
  switch (n)
    {
    case 0 : return 1; // by convention 0! = 1
    case 1 : return 1;
    case 2 : return 2;
    case 3 : return 6;
    case 4 : return 24;
    case 5 : return 5*4*3*2;
    case 6 : return 6*5*4*3*2;
    case 7 : return 7*6*5*4*3*2;
    case 8 : return 8*7*6*5*4*3*2;
    case 9 : return 9*8*7*6*5*4*3*2;
    default: return 0;
    }
}

bool isCurious(const int& n)
{
  std::string s = std::to_string(n);
  if (n >= 0)
    {
      //std::cout << s << "; " << "; size=" << s.size() << "; ";
      //std::cout << s[0] << "; " << s[1] << "; " << s[2];
      int factorialOfAllNumbers{0};
      for (auto& c: s)
	{
	  //factorialOfAllNumbers += factorial(c); // does not work: 'c' is a char, not a number
	  factorialOfAllNumbers += factorial(std::stoi(std::string(1, c))); // build a string of lenght 1 with the char
	}
      if (factorialOfAllNumbers == n)
	return true;
    }
  return false;
}

int main()
{
  std::cout << "101 C++ challenges - chapter 02, challenge 09" << std::endl;
  for (int i = 0; i <= 100000; ++i)
    {
      if (isCurious(i))
	std::cout << i << " is curious." << '\n';
    }
}
