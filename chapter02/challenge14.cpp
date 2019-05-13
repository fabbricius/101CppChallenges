// Project: chap 02 challenge 14

// Write a program to determine if the integers in an array follow
// either an arithmetic or geometric progression.
// ==> An arithmetic progression is one where the difference between
// each successive pair of integers is constant, for example in the
// array [2, 4, 6, 8] the difference between the integers is always 2.
// ==> A geometric progression is one where each element in the array
// is the product of the previous integer multiplied by some constant
// or ratio, for example in the array [3, 9, 27, 81] each element is a
// result of the previous element multiplied by 3.

// To compile and launch, using the cygwin g++ compiler:
// g++ -std=c++14 challenge14.cpp && ./a.exe

// Output:
// $ g++ -std=c++14 challenge14.cpp && ./a.exe
// 101 C++ challenges - chapter 02, challenge 14
// Enter 5 numbers, press RETURN after each one:
// 3
// 5
// 7
// 9
// 11
// You entered [3 5 7 9 11 ]
// Going to test if serie is an arithmetic progression:
//     first diff computed: 2
//     new diff computed: 2 (difference between 7 and 5)
//     new diff computed: 2 (difference between 9 and 7)
//     new diff computed: 2 (difference between 11 and 9)
// isArithmetic: true
// Going to test if serie is a geometric progression:
//     first multiplicator computed: 1
//     new multiplicator computed: 1 (multiplicator between 7 and 5)
//     new multiplicator computed: 1 (multiplicator between 9 and 7)
//     new multiplicator computed: 1 (multiplicator between 11 and 9)
// isGeometric: true


// Key points to remember:

// My solution is bad, as the output is shown: 3 5 7 9 11 is seen as a
// geometric serie, which is wrong.

#include <iostream>
constexpr int MAX_LEN = 5;

bool isArithmetic(int* array)
{
  int diff = 0;
  int newDiff = 0;
  for (int i=0; i < MAX_LEN; ++i)
    {
      //std::cout << "current number: " << *array+i << std::endl;
      //std::cout << "next number: " << *(array+i+1) << std::endl;
      if (i == 0)
	continue; // nothing to do here but I wanted to go through the whole array in the for loop
      if (i == 1)
	{
	  diff = *(array+i) - *(array);
	  std::cout << "    first diff computed: " << diff << std::endl;
	}
      else
	{
	  newDiff = *(array+i) - *(array+i-1);
	  std::cout << "    new diff computed: " << newDiff << " (difference between " << *(array+i) << " and " << *(array+i-1) << ")" <<std::endl;
	  if (newDiff != diff)
	    {
	      std::cout << "    The difference is not the same. Not an arithmetic progression!" << std::endl;
	      return false;
	    }
	}
    }
  return true;
}

// Does not work with the serie 3 5 7 9 11 (multiplicator is seen as 1, which is wrong)
bool isGeometric(int* array)
{
  float mult = 0;
  float newMult = 0;
  for (int i=0; i < MAX_LEN; ++i)
    {
      //std::cout << "  current number: " << *array+i << std::endl;
      //std::cout << "  next number: " << *(array+i+1) << std::endl;
      if (i == 0)
	continue; // nothing to do here but I wanted to go through the whole array in the for loop
      if (i == 1)
	{
	  mult = *(array+i) / *(array);
	  std::cout << "    first multiplicator computed: " << mult << " (factor between " <<  *array << " and " << *(array+1) << ")" << std::endl;
	}
      else
	{
	  newMult = *(array+i) / *(array+i-1);
	  std::cout << "    new multiplicator computed: " << newMult << " (factor between " << *(array+i-1) << " and " << *(array+i) << ")" <<std::endl;
	  // check on '1' is added for the case "2 3 4 5 6" which was seen as geometric
	  // because of the multiplicator computed as '1'
	  if ((newMult != mult) || (newMult == 1))
	    {
	      std::cout << "    The multiplicator is not the same, or is 1. Not an geometric progression!" << std::endl;
	      return false;
	    }
	}
    }
  return true;
}

int main()
{
  std::cout << "101 C++ challenges - chapter 02, challenge 14" << std::endl;
  int arr[MAX_LEN];
  int a, b;
  std::cout << "Enter " << MAX_LEN << " numbers, press RETURN after each one:" << std::endl;
  for (int i = 0; i<MAX_LEN; ++i)
    {
      std::cin >> arr[i];
    }
  std::cout << "You entered [";
  for (int i = 0; i<MAX_LEN; ++i)
    {
      std::cout << arr[i] << " ";
    }
  std::cout << "]" << std::endl;
  std::cout << "    Going to test if serie is an arithmetic progression? " << std::endl;
  std::cout << "==> is this serie arithmetic: " << std::boolalpha << isArithmetic(arr) << std::endl;
  std::cout << "    Going to test if serie is a geometric progression:" << std::endl;
  std::cout << "==> is this serie a geometric progression? " << std::boolalpha << isGeometric(arr) << std::endl;
  return 0;
}


