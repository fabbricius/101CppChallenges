// Project: chap 03 challenge 16

// > Write a program that makes it easy to change the size of the array
// > and the associated code to process the array in C style as well as
// > C++ style

// My note: what is requested is absolutely unclear. I had to look at
// the solution to understand what is requested. Apparently, the goal
// is just to enter the n elements of an array and then to diplay
// them. The size of the array is fixed.

// To compile and launch, using the cygwin g++ compiler:
// g++ -std=c++14 challenge16.cpp && ./a.exe

// I did not write the C-style part. This exercise is not very
// interesting. I guess the author just want us to manipulate arrays.

// Output:
// $  g++ -std=c++14 challenge16.cpp && ./a.exe
// 101 C++ challenges - chapter 03, challenge 16
// Write element number 0 of the array (whose size is 5)
// 2
// Write element number 1 of the array (whose size is 5)
// 4
// Write element number 2 of the array (whose size is 5)
// 6
// Write element number 3 of the array (whose size is 5)
// 8
// Write element number 4 of the array (whose size is 5)
// 10
// Thanks, the array is filled. I'm going to display it:
// myArray = [2, 4, 6, 8, 10]

  
// Key points to remember:
// to declare an array, include <array>, and then declare it
// by passing two arguments to the array constructor: type and size.

#include <iostream>
#include <array>

constexpr int size = 5;

int main()
{
  std::cout << "101 C++ challenges - chapter 03, challenge 16" << std::endl;
  std::array<int,size> myArray;
  for (int i = 0; i < size; ++i)
    {
      std::cout << "Write element number " << i << " of the array (whose size is " << size << ")" << std::endl;
      std::cin >> myArray[i];
    }
  std::cout << "Thanks, the array is filled. I'm going to display it:" << std::endl;
  std::cout << "myArray = [";
  for (int i = 0; i < size; ++i)
    {
      std::cout << myArray[i];
      if (i != size - 1)
	std::cout << ", ";
    }
  std::cout << "]" << std::endl;
  return 0;
}

