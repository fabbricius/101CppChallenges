// Project: chap 02 challenge 12

// Write a program that determines the number of trailing zeros at the
// end of X! (X factorial), where X is an arbitrary number that is
// input through the keyboard. For instance, 5! is 120, so it has one
// trailing zero.
  
// To compile using the cygwin g++ compiler:
// g++ -std=c++14 challenge12.cpp && ./a.exe

// Output:
// $ g++ -std=c++14 challenge12.cpp && ./a.exe
// 101 C++ challenges - chapter 02, challenge 12
// Enter a number: 6
// factorial(6) is 720. Number of trailing zeros of 720 is 1


// Key points to remember:
// My solution is bad. As the author says in the book:
// > This approach has a serious limitation.
// > The range of an int would be quickly exceeded while calculating the factorial value.
// > So this approach would give wrong results beyond 13!. Hence we have used a
// > different approach to count the trailing zeros.
// 
// A better solution is shown in the book.

#include <iostream>

int factorial(const int& n)
{
  if (n == 0)
    return 1;
  else
    return n*factorial(n-1);
}

int returnNumberOfTrailingZeros(const int& n)
{
  std::string s = std::to_string(n);
  int ret = 0;
  for(int i=0;i<s.size();++i)
    {
      if (s[s.size() - 1 -i ] != '0')
	return ret;
      else
	ret++;
    }
  return ret;
}

int main()
{
  int i;  
  std::cout << "101 C++ challenges - chapter 02, challenge 12" << std::endl;
  std::cout << "Enter a number: ";
  std::cin >> i;
  std::cout << "factorial("<< i << ") is "<< factorial(i);;
  std::cout << ". Number of trailing zeros of "<< factorial(i) << " is "<< returnNumberOfTrailingZeros(factorial(i)) << std::endl;
  /*
  // some testing...
  i=0;
  std::cout << "factorial("<< i << ")="<< factorial(i) << std::endl;
  i=1;
  std::cout << "factorial("<< i << ")="<< factorial(i) << std::endl;
  i=2;
  std::cout << "factorial("<< i << ")="<< factorial(i) << std::endl;
  i=3;
  std::cout << "factorial("<< i << ")="<< factorial(i) << std::endl;
  i=4;
  std::cout << "factorial("<< i << ")="<< factorial(i) << std::endl;
  */
  return 0;
}
