// Project: chap 02 challenge 13
// A triplet of positive integers (a,b,c) is called a Cardano Triplet if it satisfies the condition:
//      ___________            ___________ 
// /\ 3/        _         /\ 3/        _  `
//   \/ (a + b\/c`    +     \/ (a - b\/c`    =  1
// For example, (2,1,5) is a Cardano Triplet.
// Write a progam to generate all Cardano Triplets that exist, such that (a + b + c) <= 100.

// My note: if my ascii-art is too bad, here is the formula:
// cubic root(a+b*square root(c)) + cubic root(a-b*square root(c)) = 1

// To compile and launch, using the cygwin g++ compiler:
// g++ -std=c++14 challenge13.cpp && ./a.exe

// Output:
// We have a Cardino triplet: (2, 1, 5)
// We have a Cardino triplet: (5, 1, 52)
// We have a Cardino triplet: (5, 2, 13)
// We have a Cardino triplet: (8, 3, 21)
// We have a Cardino triplet: (11, 4, 29)
// We have a Cardino triplet: (14, 5, 37)
// We have a Cardino triplet: (17, 6, 45)
// We have a Cardino triplet: (17, 9, 20)
// We have a Cardino triplet: (17, 18, 5)
// We have a Cardino triplet: (20, 7, 53)
// We have a Cardino triplet: (23, 8, 61)

// Key points to remember:

#include <iostream>
#include <math.h>

void printCardanoTriplet (const int& a, const int& b, const int& c)
{
  // check that we are in the limit
  if (a + b + c <= 100)
    {
      float res = std::cbrt(a + b*std::sqrt(c)) + std::cbrt(a - b*std::sqrt(c));
      if (res == 1.0)
	{
	  std::cout << "We have a Cardino triplet: (" << a << ", " << b << ", " << c << ")" << std::endl;
	}
    }
}

int main()
{
  std::cout << "101 C++ challenges - chapter 02, challenge 13" << std::endl;
  for (int a = 0; a <= 100; ++a)
    {
      for (int b = 0; b <= 100; ++b)
	{
	  for (int c = 0; c <= 100; ++c)
	    {
	      printCardanoTriplet(a,b,c);
	    }
	}
    }
  printCardanoTriplet(1,2,3);
  return 0;
}


