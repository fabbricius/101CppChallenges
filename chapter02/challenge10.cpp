// Project: chap 02 challenge 10

// The Fibonacci sequence is defined by the recurrence relation:
// F(n)= F (n - 1) + F (n - 2), where F(1) = 1 and F(2) = 1.
// Hence the first 12 terms will be:
// F(1) = 1   F(7) = 13
// F(2) = 1   F(8) = 21
// F(3) = 2   F(9) = 34
// F(4) = 3   F(10) = 55
// F(5) = 5   F(11) = 89
// F(6) = 8   F(12) = 144
// The 12th term, F(12), is the first term to contain three digits.
// Write a program to find the index of the first term in the Fibonacci sequence to contain 10 digits?
  
// To compile using the cygwin g++ compiler:
// g++ -std=c++14 challenge10.cpp && ./a.exe

// Output:
// farband@N-5CG6074QC8 /cygdrive/c/Users/farband/Documents/home/snippet/Cpp/101cha
// $ g++ -std=c++14 challenge10.cpp && ./a.exe
// 101 C++ challenges - chapter 02, challenge 10: Fibonacci
// F(1) = 1
// F(2) = 1
// F(3) = 2
// F(4) = 3
// F(5) = 5
// F(6) = 8
// F(7) = 13
// F(8) = 21
// F(9) = 34
// F(10) = 55
// F(11) = 89
// F(12) = 144
// F(13) = 233
// F(14) = 377
// F(15) = 610
// F(16) = 987
// F(17) = 1597
// F(18) = 2584
// F(19) = 4181
// F(20) = 6765
// F(21) = 10946
// F(22) = 17711
// F(23) = 28657
// F(24) = 46368
// F(25) = 75025
// F(26) = 121393
// F(27) = 196418
// F(28) = 317811
// F(29) = 514229
// F(30) = 832040
// F(31) = 1346269
// F(32) = 2178309
// F(33) = 3524578
// F(34) = 5702887
// F(35) = 9227465
// F(36) = 14930352
// F(37) = 24157817
// F(38) = 39088169
// F(39) = 63245986
// F(40) = 102334155
// F(41) = 165580141
// F(42) = 267914296
// F(43) = 433494437
// F(44) = 701408733
// F(45) = 1134903170
// The Fibonacci reaches 10 digit at index 45


#include <iostream>

int main()
{
  std::cout << "101 C++ challenges - chapter 02, challenge 10: Fibonacci" << std::endl;
  int nMinusTwo{1};
  int nMinusOne{1};
  int nCurrent{0};
  int index{3};
  bool keepGoing{true};
  std::cout << "F(1) = " << nMinusTwo << std::endl;
  std::cout << "F(2) = " << nMinusOne << std::endl;
  while (keepGoing)
    {
      nCurrent = nMinusTwo + nMinusOne;
      std::cout << "F("<< index << ") = " << nCurrent << std::endl;
      if (nCurrent >= 1000000000)
	keepGoing = false;
      else
	{
	  nMinusTwo = nMinusOne;
	  nMinusOne = nCurrent;
	  ++index;
	}
    }
  std::cout << "The Fibonacci reaches 10 digit at index "<< index << std::endl;
  return 0;
}
