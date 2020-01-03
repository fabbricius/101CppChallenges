// Project: chap 03 challenge 17

// > Write a program that receives the size of an array and then
// > allocates memory for it dynamically. Further, receive numbers
// > into this array and print them on screen. The program should use
// > C and C++ styles to accomplish these tasks.

// My note: the author is expecting us to use old-fashined arrays
// allocated with 'new' and pointers to access the array, and even
// malloc for the C-part (he does that in the solution). The goal was
// probably to make the students use something like myPointer++ to
// navigate through the array and *myPointer to access the array. In a
// modern-C++ perspective, it's better to use std::array and the
// initialisation is done by the constructor. Problem is, std::array
// cannot have its size set during runtime. It has to be known during
// compilation. So I did here as the author intended. Anyway, I find
// that the author's code is outdated (like the whole book in fact).

// To compile and launch, using the cygwin g++ compiler:
// g++ -std=c++14 challenge17.cpp && ./a.exe

// I did not write the C-style part (malloc), it's absolutely useless.

// Output:
// $ g++ -std=c++14 challenge17.cpp && ./a.exe
// 101 C++ challenges - chapter 03, challenge 17
// Please enter a size for the array:
// 3
// Write element number 0 of the array (whose size is 3)
// 3
// Write element number 1 of the array (whose size is 3)
// 2
// Write element number 2 of the array (whose size is 3)
// 0
// Thanks, the array is filled. I'm going to display it:
// myArray = [3, 2, 0]

  
// Key points to remember:
// make sure to use the delete[] as it is an array allocated with new [].
// See Scott Meyers Effective C++, second edition:
// "Item 5:  Use the same form in corresponding uses of new and delete." 
// See also:
// https://stackoverflow.com/questions/1641957/is-an-array-name-a-pointer
// In a modern C++ environment (which this book does not use), use the std::array

#include <iostream>

int main()
{
  std::cout << "101 C++ challenges - chapter 03, challenge 17" << std::endl;
  int size{0};

  std::cout << "Please enter a size for the array:" << std::endl;
  std::cin >> size;
  int* myArray = new int[size]; // declare pointer to int and allocate memory.
  int* myArrayPtr = myArray; // Declare a pointer and set to point to the array. Equivalent to int* myArrayPtr = &myArray[0];
  if (&myArray != nullptr)
    {
      for (int i = 0; i < size; ++i)
	{
	  std::cout << "Write element number " << i << " of the array (whose size is " << size << ")" << std::endl;
	  std::cin >> myArray[i]; // access the value with the [] notation
	}
    }
  // Now we're going to display it. To browse the value we will use a different way than for the init:
  // we will use the pointer declared aside the array and we will update the pointer with the '++' operator.
  std::cout << "Thanks, the array is filled. I'm going to display it:" << std::endl;
  std::cout << "myArray = [";
  for (int i = 0; i < size; ++i)
    {
      std::cout << *myArrayPtr;
      if (i != size - 1)
	{
	  myArrayPtr++; // ... and increase the pointer so it will points to the new value in the array
	  std::cout << ", ";
	}
    }
  std::cout << "]" << std::endl;
  delete [] myArray;
  myArrayPtr = nullptr;
  return 0;
}

